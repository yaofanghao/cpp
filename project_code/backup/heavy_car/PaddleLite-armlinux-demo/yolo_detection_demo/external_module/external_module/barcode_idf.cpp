void barcode_identify(ImageScanner &scanner, Mat &frame)
{
    Mat frame_grayscale;
    cvtColor(frame, frame_grayscale, COLOR_RGB2GRAY);
    int width = frame_grayscale.cols;
    int height = frame_grayscale.rows;
    uchar *raw = (uchar *)(frame_grayscale.data);
    Image image(width, height, "Y800", raw, width * height);
    scanner.scan(image);
    int counter = 0;
    for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
        time_t now;
        tm *current;
        now = time(0);
        current = localtime(&now);

        // do something useful with results
        cout    << "[" << current->tm_hour << ":" << current->tm_min << ":" << setw(2) << setfill('0') << current->tm_sec << "] " << counter << " "
                << "decoded " << symbol->get_type_name()
                << " symbol \"" << symbol->get_data() << '"' << endl;
        counter++;
    }
    if (counter == 0)
    {
        LOG(INFO) << "No Barcode indentify";
    }
    
}