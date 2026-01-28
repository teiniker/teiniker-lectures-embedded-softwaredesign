
class BookDTO:
    """Transfer object for Book data"""
    def __init__(self, oid:int, author:str, isbn:str) -> None:
        self.oid = oid
        self.author = author
        self.isbn = isbn

