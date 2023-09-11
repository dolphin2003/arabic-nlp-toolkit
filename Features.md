

## Convert numbers into spoken form (تفقيط) :
```python
anltk.tafqit(1934)
# 'ألف وتسعمائة وأربعة وثلاثون'
anltk.tafqit(1934, anltk.TafqitOptions(is_feminine=True))
# 'ألف وتسعمائة وأربع وثلاثون'
```

## Transliteration. converting between Characters Mapping
```python
# Buckwalter
anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ", anltk.AR2BW)
# '>bjd hwz HTy klmn sEfS qr$t vx* DZg'

# Safe Buckwalter
anltk.transliterate("أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ", anltk.AR2SBW)
# 'Objd hwz HTy klmn sEfS qrct vxV DZg'


anltk.transliterate(">bjd hwz HTy klmn sEfS qr$t vx* DZg", anltk.BW2AR)
# 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'


anltk.transliterate("Objd hwz HTy klmn sEfS qrct vxV DZg", anltk.SBW2AR)
# 'أبجد هوز حطي كلمن سعفص قرشت ثخذ ضظغ'
```


## Tokenization

```python
anltk.tokenize_words('في السّاعة الثانية, ذهبنا على البيت جميعا!! وعدنا معاً.')
# ['في', 'السّاعة', 'الثانية', ',', 'ذهبنا', 'على', 'البيت', 'جميعا', '!!', 'وعدنا', 'معاً', '.']
```


## Utilities :

```python
# if the literal in anltk.constants.HARAKAT 
anltk.is_tashkeel('ي') # False
anltk.is_tashkeel('ِ') # True 

# if the literal in anltk.constants.ALPHABET
anltk.is_arabic_alpha('h') # False
anltk.is_arabic_alpha('أ') # True

# if a character is shamsi
anltk.is_shamsi('ش')
#	True
# 