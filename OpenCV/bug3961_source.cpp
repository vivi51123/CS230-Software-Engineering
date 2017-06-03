//Fixes: https://github.com/opencv/opencv/pull/3346/files

//Line 16 is causing the memory leak
//Comment 16 out and use 17 to see if memory leak goes away

#include "precomp.hpp"

namespace cv { namespace viz
{
    vtkStandardNewMacro(vtkImageMatSource);
}}

cv::viz::vtkImageMatSource::vtkImageMatSource()
{
    this->SetNumberOfInputPorts(0);
    this->ImageData = vtkImageData::New(); // Causing bug
    //this->ImageData = vtkSmartPointer<vtkImageData>::New(); //fix
}

int cv::viz::vtkImageMatSource::RequestInformation(vtkInformation *, vtkInformationVector**, vtkInformationVector *outputVector)
{
    vtkInformation* outInfo = outputVector->GetInformationObject(0);

    outInfo->Set(vtkStreamingDemandDrivenPipeline::WHOLE_EXTENT(), this->ImageData->GetExtent(), 6);
    outInfo->Set(vtkDataObject::SPACING(), 1.0, 1.0, 1.0);
    outInfo->Set(vtkDataObject::ORIGIN(),  0.0, 0.0, 0.0);

    vtkDataObject::SetPointDataActiveScalarInfo(outInfo, this->ImageData->GetScalarType(), this->ImageData->GetNumberOfScalarComponents());
    return 1;
}

int cv::viz::vtkImageMatSource::RequestData(vtkInformation*, vtkInformationVector**, vtkInformationVector *outputVector)
{
     vtkInformation *outInfo = outputVector->GetInformationObject(0);

     vtkImageData *output = vtkImageData::SafeDownCast(outInfo->Get(vtkDataObject::DATA_OBJECT()) );
     output->ShallowCopy(this->ImageData);
     return 1;
}

void cv::viz::vtkImageMatSource::SetImage(InputArray _image)
{
    CV_Assert(_image.depth() == CV_8U && (_image.channels() == 1 || _image.channels() == 3 || _image.channels() == 4));

    Mat image = _image.getMat();

    this->ImageData->SetDimensions(image.cols, image.rows, 1);
#if VTK_MAJOR_VERSION <= 5
    this->ImageData->SetNumberOfScalarComponents(image.channels());
    this->ImageData->SetScalarTypeToUnsignedChar();
    this->ImageData->AllocateScalars();
#else
    this->ImageData->AllocateScalars(VTK_UNSIGNED_CHAR, image.channels());
#endif

    switch(image.channels())
    {
    case 1: copyGrayImage(image, this->ImageData); break;
    case 3: copyRGBImage (image, this->ImageData); break;
    case 4: copyRGBAImage(image, this->ImageData); break;
    }
    this->ImageData->Modified();
}

void cv::viz::vtkImageMatSource::copyGrayImage(const Mat &source, vtkSmartPointer<vtkImageData> output)
{
    unsigned char* dptr = reinterpret_cast<unsigned char*>(output->GetScalarPointer());
    size_t elem_step = output->GetIncrements()[1]/sizeof(unsigned char);

    for (int y = 0; y < source.rows; ++y)
    {
        unsigned char* drow = dptr + elem_step * y;
        const unsigned char *srow = source.ptr<unsigned char>(y);
        for (int x = 0; x < source.cols; ++x)
            drow[x] = *srow++;
    }
}

void cv::viz::vtkImageMatSource::copyRGBImage(const Mat &source, vtkSmartPointer<vtkImageData> output)
{
    Vec3b* dptr = reinterpret_cast<Vec3b*>(output->GetScalarPointer());
    size_t elem_step = output->GetIncrements()[1]/sizeof(Vec3b);

    for (int y = 0; y < source.rows; ++y)
    {
        Vec3b* drow = dptr + elem_step * y;
        const unsigned char *srow = source.ptr<unsigned char>(y);
        for (int x = 0; x < source.cols; ++x, srow += source.channels())
            drow[x] = Vec3b(srow[2], srow[1], srow[0]);
    }
}

void cv::viz::vtkImageMatSource::copyRGBAImage(const Mat &source, vtkSmartPointer<vtkImageData> output)
{
    Vec4b* dptr = reinterpret_cast<Vec4b*>(output->GetScalarPointer());
    size_t elem_step = output->GetIncrements()[1]/sizeof(Vec4b);

    for (int y = 0; y < source.rows; ++y)
    {
        Vec4b* drow = dptr + elem_step * y;
        const unsigned char *srow = source.ptr<unsigned char>(y);
        for (int x = 0; x < source.cols; ++x, srow += source.channels())
            drow[x] = Vec4b(srow[2], srow[1], srow[0], srow[3]);
    }
}
