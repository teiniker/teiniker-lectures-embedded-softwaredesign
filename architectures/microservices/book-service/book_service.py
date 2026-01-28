from http import HTTPStatus
from flask import Flask, jsonify, request

# Simulate a database table in a list
table = [
    {'id':1, 'author':'Eric Matthes','title':'Python Crash Course', 'isbn':'978-1718502703'},
    {'id':2, 'author':'Brett Slatkin','title':'Effective Python', 'isbn':'978-0134853987'},
    {'id':3, 'author':'Luciano Ramalho','title':'Fluent Python', 'isbn':'978-1492056355'}
]

app = Flask(__name__)

@app.route('/books', methods = ['GET'])
def find_all():
    return jsonify({'data': table}), HTTPStatus.OK


@app.route('/books/<int:oid>', methods = ['GET'])
def find_by_id(oid):
    for item in table:
        print(item)
        if item['id'] == oid:
            return jsonify(item), HTTPStatus.OK
    return jsonify({'message': 'book not found'}), HTTPStatus.NOT_FOUND


@app.route('/books', methods=['POST'])
def insert():
    data = request.get_json()
    print(data)
    oid = data.get('id')
    author = data.get('author')
    title = data.get('title')
    isbn = data.get('isbn')
    book = {
        'id': oid,
        'author': author,
        'title': title,
        'isbn': isbn
    }
    table.append(book)
    return jsonify(book), HTTPStatus.CREATED


@app.route('/books/<int:oid>', methods=['PUT'])
def update(oid):
    for item in table:
        print(item)
        if item['id'] == oid:
            data = request.get_json()
            print(data)
            item.update({'author':data.get('author'), 'title':data.get('title'), 'isbn':data.get('isbn')})
            return jsonify(item), HTTPStatus.OK
    return jsonify({'message': 'book not found'}), HTTPStatus.NOT_FOUND


@app.route('/books/<int:oid>', methods=['DELETE'])
def delete(oid):
    for item in table:
        print(item)
        if item['id'] == oid:
            table.remove(item)
            return '', HTTPStatus.NO_CONTENT
    return jsonify({'message': 'book not found'}), HTTPStatus.NOT_FOUND


if __name__ == '__main__':
    app.run(port=8080, debug=True)
