# About PDF

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

- White Space Characters
  | decimal | hexadecimal | octal | name |
  |:---:|:---:|:---:|:---:|
  |0|00|000|Null(NUL)|
  |9|09|011|HORIZONTAL TAB(HT)|
  |10|0A|012|LINE FEED(LF)|
  |12|0C|014|FORM FEED(FF)|
  |13|0D|015|CARRIAGE RETURN(CR)|
  |32|20|040|SPACE(SP)|
- Delimiter Characters
  |glyph|decimal|hexadecimal|octal|name|
  |:---:|:---:|:---:|:---:|:---:|
  |(|40|28|50|LEFT PARENTHESIS|
  |)|41|29|51|RIGHT PARENTHESIS|
  |<|60|3C|60|LESS-THAN SIGN|
  |>|62|3E|62|GREATER-THAN SIGN|
  |[|91|5B|133|LEFT SQUARE BRACKET|
  |]|93|5D|135|RIGHT SQUARE BRACKET|
  |{|123|7B|173|LEFT CURLY BRACKET|
  |}|125|7D|175|RIGHT CURLY BRACKET|
  |/|47|2F|57|SOLIDUS|
  |%|37|25|45|PERCENT SIGN|
- Comments
  started by PERCENT SIGN(25H), up to end of line.

  ```pdf
  abc% comment (/%) blah blah
  123
  ```

- Objects
  - basic types of objects
    - boolean objects

      ```boolean
      true
      false
      ```

    - numeric objects(integer and real)

      ```integer objects
      123 43445 +17 -98 0
      ```

      ```real objects
      34.5 -3.62 +123.6 4. -.002 0.0
      ```

    - string objects

      ```sequence of literal characters
      (This is a sample string)
      (This is another string
      contain newline)
      (strings may contains () and (*!&^%).)
      ()
      (zero(0) length string)
      (reverse solidus(\, 5C, backslash) is used as an escape character)
      (These \
      two strings \
      are the same.)
      (These two strings are the same.)
      ```

      |sequence|meaning|
      |:---:|:---:|
      |\n|LINE FEED (0Ah) (LF)|
      |\r|CARRIAGE RETURN (0Dh) (CR)|
      |\t|HORIZONTAL TAB (09h) (HT)|
      |\b|BACKSPACE (08h) (BS)|
      |\f|FORM FEED (FF)|
      |\\( |LEFT PARENTHESIS (28h)|
      |\\) |RIGHT PARENTHESIS (29h)|
      |\\\\ |REVERSE SOLIDUS (5Ch) (Backslash)|
      |\ddd|Character code ddd (octal)|
      |\\ |at the end of a line, indicate the string continues on the following line.|
      |   |end-of-line marker without REVERSE SOLIDUS shall be treated as 0Ah.|

      ```hexadecimal data
      <0123456789ABCDEF>
      <901FA3> => <90><1F><A3>
      <901FA> => <90><1F><A0>
      ```

    - name objects
    - array
    - dictionary
    - stream
    - null
  - indirect object
