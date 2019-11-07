# Working with PDF files in Python
https://www.geeksforgeeks.org/working-with-pdf-files-in-python/


## Rotate
    rotate_example.py

    Some important points related to above code:

    For rotation, we first create pdf reader object of the original pdf.
    pdfWriter = PyPDF2.PdfFileWriter()
    Rotated pages will be written to a new pdf. For writing to pdfs, we use object of PdfFileWriter class of PyPDF2 module.

    for page in range(pdfReader.numPages):
            pageObj = pdfReader.getPage(page)
            pageObj.rotateClockwise(rotation)
            pdfWriter.addPage(pageObj)
    Now, we iterate each page of original pdf. We get page object by getPage() method of pdf reader class. Now, we rotate the page by rotateClockwise() method of page object class. Then, we add page to pdf writer object using addPage() method of pdf writer class by passing the rotated page object.

    newFile = open(newFileName, 'wb')
    pdfWriter.write(newFile)
    pdfFileObj.close()
    newFile.close()
    Now, we have to write the pdf pages to a new pdf file. Firstly we open the new file object and write pdf pages to it using write() method of pdf writer object. Finally, we close the original pdf file object and the new file object.
## Merge
    merge_example.py

    Output of above program is a combined pdf, combined_example.pdf obtained by merging example.pdf and rotated_example.pdf.

    Let us have a look at important aspects of this program:

    pdfMerger = PyPDF2.PdfFileMerger()
    For merging, we use a pre-built class, PdfFileMerger of PyPDF2 module.
    Here, we create an object pdfMerger of pdf merger class

    for pdf in pdfs:
            with open(pdf, 'rb') as f:
                pdfMerger.append(f)
    Now, we append file object of each pdf to pdf merger object using append() method.

    with open(output, 'wb') as f:
            pdfMerger.write(f)
    Finally, we write the pdf pages to the output pdf file using write method of pdf merger object.
## --