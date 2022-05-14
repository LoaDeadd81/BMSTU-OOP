#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include <initializer_list>
#include "ObjectVisitor.h"

using namespace std;

class Object
{
public:
    virtual ~Object()=default;
    virtual bool isVisible() const {return false;};
    virtual bool isComposite() const {return false;};
    virtual bool isViewer() const {return false;};
    virtual vector<Object>::iterator begin() {return vector<Object>::iterator(nullptr);};
    virtual vector<Object>::iterator end() {return vector<Object>::iterator(nullptr);};
    virtual vector<Object>::const_iterator cbegin() const {return vector<Object>::const_iterator (nullptr);};
    virtual vector<Object>::const_iterator cend() const {return vector<Object>::const_iterator(nullptr);};
    virtual size_t get_size() const {return 0;};
    virtual void addObject(Object &obj) {};
    virtual void removeObject(vector<Object>::iterator iter) {};
    virtual void accept(const ObjectVisitor &Visitor) = 0;
};

class SimpleObjects : public Object
{
    virtual ~SimpleObjects() override =default;
};

class Composite : public Object
{
public:
    Composite() = default;
    virtual ~Composite() override =default;
    Composite(const Composite& obj);
    Composite(initializer_list<Object> init_list);
    Composite &operator=(const Composite& obj);
    Object &operator[](int i);
    const Object &operator[](int i) const;
    virtual bool isComposite() const override;
    virtual vector<Object>::iterator begin() override;
    virtual vector<Object>::iterator end() override;
    virtual vector<Object>::const_iterator cbegin() const override;
    virtual vector<Object>::const_iterator cend() const override;
    virtual size_t get_size() const override;
    virtual void addObject(Object &obj) override;
    virtual void removeObject(vector<Object>::iterator iter) override;
    virtual void accept(const ObjectVisitor &Visitor);
private:
    vector<Object> objects;
};
#endif
