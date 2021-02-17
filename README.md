# pdfviewer

- Portable Document Format(PDF)
- ISO 32000
- based on the PostScript language

## ISO 32000

> https://www.iso.org/standard/75839.html

- http://wwwimages.adobe.com/www.adobe.com/content/dam/acom/en/devnet/pdf/pdfs/PDF32000_2008.pdf
  - [PDF32000_2008.pdf local copy](ref/PDF32000_2008.pdf)

### File Structure

---

| header |
|:---:|
| body |
| cross-reference table |
| trailer |

---

- header
  - one line.
  - version of the PDF specification to which the file conforms.
- body
  - contains objects that make up the document.
- cross-reference table
  - contains information about the indirect objects.
- trailer
  - location of the cross-reference table.
  - location of certain special objects.

### File Header

```binary
%PDF-{version}
```

form of the {version} is 1.N, where N is a digit between 0 and 7.

### Syntax

- Objects
  - Lexical Conventions
  - Objects
  - Stream Objects
- File structure
  - File structure
  - Encryption
- Document structure
  - Document structure
- Content streams
  - Content Streams and Resources
