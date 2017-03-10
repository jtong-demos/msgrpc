/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "api_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace org { namespace example { namespace msgrpc { namespace thrift {


SingleOptionalFieldStruct::~SingleOptionalFieldStruct() throw() {
}


void SingleOptionalFieldStruct::__set_value(const int16_t val) {
  this->value = val;
__isset.value = true;
}

void SingleOptionalFieldStruct::__set_value64(const int64_t val) {
  this->value64 = val;
}

uint32_t SingleOptionalFieldStruct::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->value);
          this->__isset.value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->value64);
          this->__isset.value64 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t SingleOptionalFieldStruct::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SingleOptionalFieldStruct");

  if (this->__isset.value) {
    xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_I16, 1);
    xfer += oprot->writeI16(this->value);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldBegin("value64", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->value64);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SingleOptionalFieldStruct &a, SingleOptionalFieldStruct &b) {
  using ::std::swap;
  swap(a.value, b.value);
  swap(a.value64, b.value64);
  swap(a.__isset, b.__isset);
}

SingleOptionalFieldStruct::SingleOptionalFieldStruct(const SingleOptionalFieldStruct& other0) {
  value = other0.value;
  value64 = other0.value64;
  __isset = other0.__isset;
}
SingleOptionalFieldStruct& SingleOptionalFieldStruct::operator=(const SingleOptionalFieldStruct& other1) {
  value = other1.value;
  value64 = other1.value64;
  __isset = other1.__isset;
  return *this;
}
void SingleOptionalFieldStruct::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SingleOptionalFieldStruct(";
  out << "value="; (__isset.value ? (out << to_string(value)) : (out << "<null>"));
  out << ", " << "value64=" << to_string(value64);
  out << ")";
}


EmbeddedStruct::~EmbeddedStruct() throw() {
}


void EmbeddedStruct::__set_es_i8(const int8_t val) {
  this->es_i8 = val;
}

void EmbeddedStruct::__set_es_i16(const int16_t val) {
  this->es_i16 = val;
}

uint32_t EmbeddedStruct::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->es_i8);
          this->__isset.es_i8 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->es_i16);
          this->__isset.es_i16 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EmbeddedStruct::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EmbeddedStruct");

  xfer += oprot->writeFieldBegin("es_i8", ::apache::thrift::protocol::T_BYTE, 1);
  xfer += oprot->writeByte(this->es_i8);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("es_i16", ::apache::thrift::protocol::T_I16, 2);
  xfer += oprot->writeI16(this->es_i16);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EmbeddedStruct &a, EmbeddedStruct &b) {
  using ::std::swap;
  swap(a.es_i8, b.es_i8);
  swap(a.es_i16, b.es_i16);
  swap(a.__isset, b.__isset);
}

EmbeddedStruct::EmbeddedStruct(const EmbeddedStruct& other2) {
  es_i8 = other2.es_i8;
  es_i16 = other2.es_i16;
  __isset = other2.__isset;
}
EmbeddedStruct& EmbeddedStruct::operator=(const EmbeddedStruct& other3) {
  es_i8 = other3.es_i8;
  es_i16 = other3.es_i16;
  __isset = other3.__isset;
  return *this;
}
void EmbeddedStruct::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EmbeddedStruct(";
  out << "es_i8=" << to_string(es_i8);
  out << ", " << "es_i16=" << to_string(es_i16);
  out << ")";
}


ResponseData::~ResponseData() throw() {
}


void ResponseData::__set_pet_id(const int32_t val) {
  this->pet_id = val;
}

void ResponseData::__set_pet_name(const std::string& val) {
  this->pet_name = val;
}

void ResponseData::__set_pet_weight(const int32_t val) {
  this->pet_weight = val;
}

void ResponseData::__set_pet_i8_value(const int8_t val) {
  this->pet_i8_value = val;
}

void ResponseData::__set_pet_i16_value(const int16_t val) {
  this->pet_i16_value = val;
}

void ResponseData::__set_pet_i64_value(const int64_t val) {
  this->pet_i64_value = val;
}

void ResponseData::__set_pet_double_value(const double val) {
  this->pet_double_value = val;
}

void ResponseData::__set_pet_bool_value(const bool val) {
  this->pet_bool_value = val;
}

void ResponseData::__set_pet_binary_value(const std::string& val) {
  this->pet_binary_value = val;
}

void ResponseData::__set_pet_embedded_struct(const EmbeddedStruct& val) {
  this->pet_embedded_struct = val;
}

void ResponseData::__set_pet_list_i32(const std::vector<int32_t> & val) {
  this->pet_list_i32 = val;
}

void ResponseData::__set_pet_list_of_struct(const std::vector<EmbeddedStruct> & val) {
  this->pet_list_of_struct = val;
}

void ResponseData::__set_pet_list_of_bool(const std::vector<bool> & val) {
  this->pet_list_of_bool = val;
}

void ResponseData::__set_pet_set_of_i32(const std::set<int32_t> & val) {
  this->pet_set_of_i32 = val;
}

void ResponseData::__set_pet_set_of_struct(const std::set<EmbeddedStruct> & val) {
  this->pet_set_of_struct = val;
}

void ResponseData::__set_pet_map_i32_string(const std::map<int32_t, std::string> & val) {
  this->pet_map_i32_string = val;
}

void ResponseData::__set_pet_map_string_struct(const std::map<std::string, EmbeddedStruct> & val) {
  this->pet_map_string_struct = val;
}

uint32_t ResponseData::read(::apache::thrift::protocol::TProtocol* iprot) {

  apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->pet_id);
          this->__isset.pet_id = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->pet_name);
          this->__isset.pet_name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->pet_weight);
          this->__isset.pet_weight = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->pet_i8_value);
          this->__isset.pet_i8_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I16) {
          xfer += iprot->readI16(this->pet_i16_value);
          this->__isset.pet_i16_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->pet_i64_value);
          this->__isset.pet_i64_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_DOUBLE) {
          xfer += iprot->readDouble(this->pet_double_value);
          this->__isset.pet_double_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->pet_bool_value);
          this->__isset.pet_bool_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->pet_binary_value);
          this->__isset.pet_binary_value = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->pet_embedded_struct.read(iprot);
          this->__isset.pet_embedded_struct = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->pet_list_i32.clear();
            uint32_t _size4;
            ::apache::thrift::protocol::TType _etype7;
            xfer += iprot->readListBegin(_etype7, _size4);
            this->pet_list_i32.resize(_size4);
            uint32_t _i8;
            for (_i8 = 0; _i8 < _size4; ++_i8)
            {
              xfer += iprot->readI32(this->pet_list_i32[_i8]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.pet_list_i32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->pet_list_of_struct.clear();
            uint32_t _size9;
            ::apache::thrift::protocol::TType _etype12;
            xfer += iprot->readListBegin(_etype12, _size9);
            this->pet_list_of_struct.resize(_size9);
            uint32_t _i13;
            for (_i13 = 0; _i13 < _size9; ++_i13)
            {
              xfer += this->pet_list_of_struct[_i13].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.pet_list_of_struct = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->pet_list_of_bool.clear();
            uint32_t _size14;
            ::apache::thrift::protocol::TType _etype17;
            xfer += iprot->readListBegin(_etype17, _size14);
            this->pet_list_of_bool.resize(_size14);
            uint32_t _i18;
            for (_i18 = 0; _i18 < _size14; ++_i18)
            {
              xfer += iprot->readBool(this->pet_list_of_bool[_i18]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.pet_list_of_bool = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_SET) {
          {
            this->pet_set_of_i32.clear();
            uint32_t _size19;
            ::apache::thrift::protocol::TType _etype22;
            xfer += iprot->readSetBegin(_etype22, _size19);
            uint32_t _i23;
            for (_i23 = 0; _i23 < _size19; ++_i23)
            {
              int32_t _elem24;
              xfer += iprot->readI32(_elem24);
              this->pet_set_of_i32.insert(_elem24);
            }
            xfer += iprot->readSetEnd();
          }
          this->__isset.pet_set_of_i32 = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_SET) {
          {
            this->pet_set_of_struct.clear();
            uint32_t _size25;
            ::apache::thrift::protocol::TType _etype28;
            xfer += iprot->readSetBegin(_etype28, _size25);
            uint32_t _i29;
            for (_i29 = 0; _i29 < _size25; ++_i29)
            {
              EmbeddedStruct _elem30;
              xfer += _elem30.read(iprot);
              this->pet_set_of_struct.insert(_elem30);
            }
            xfer += iprot->readSetEnd();
          }
          this->__isset.pet_set_of_struct = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 16:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->pet_map_i32_string.clear();
            uint32_t _size31;
            ::apache::thrift::protocol::TType _ktype32;
            ::apache::thrift::protocol::TType _vtype33;
            xfer += iprot->readMapBegin(_ktype32, _vtype33, _size31);
            uint32_t _i35;
            for (_i35 = 0; _i35 < _size31; ++_i35)
            {
              int32_t _key36;
              xfer += iprot->readI32(_key36);
              std::string& _val37 = this->pet_map_i32_string[_key36];
              xfer += iprot->readString(_val37);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.pet_map_i32_string = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 17:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->pet_map_string_struct.clear();
            uint32_t _size38;
            ::apache::thrift::protocol::TType _ktype39;
            ::apache::thrift::protocol::TType _vtype40;
            xfer += iprot->readMapBegin(_ktype39, _vtype40, _size38);
            uint32_t _i42;
            for (_i42 = 0; _i42 < _size38; ++_i42)
            {
              std::string _key43;
              xfer += iprot->readString(_key43);
              EmbeddedStruct& _val44 = this->pet_map_string_struct[_key43];
              xfer += _val44.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.pet_map_string_struct = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ResponseData::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ResponseData");

  xfer += oprot->writeFieldBegin("pet_id", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->pet_id);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->pet_name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_weight", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->pet_weight);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_i8_value", ::apache::thrift::protocol::T_BYTE, 4);
  xfer += oprot->writeByte(this->pet_i8_value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_i16_value", ::apache::thrift::protocol::T_I16, 5);
  xfer += oprot->writeI16(this->pet_i16_value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_i64_value", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->pet_i64_value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_double_value", ::apache::thrift::protocol::T_DOUBLE, 7);
  xfer += oprot->writeDouble(this->pet_double_value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_bool_value", ::apache::thrift::protocol::T_BOOL, 8);
  xfer += oprot->writeBool(this->pet_bool_value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_binary_value", ::apache::thrift::protocol::T_STRING, 9);
  xfer += oprot->writeBinary(this->pet_binary_value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_embedded_struct", ::apache::thrift::protocol::T_STRUCT, 10);
  xfer += this->pet_embedded_struct.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_list_i32", ::apache::thrift::protocol::T_LIST, 11);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->pet_list_i32.size()));
    std::vector<int32_t> ::const_iterator _iter45;
    for (_iter45 = this->pet_list_i32.begin(); _iter45 != this->pet_list_i32.end(); ++_iter45)
    {
      xfer += oprot->writeI32((*_iter45));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_list_of_struct", ::apache::thrift::protocol::T_LIST, 12);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->pet_list_of_struct.size()));
    std::vector<EmbeddedStruct> ::const_iterator _iter46;
    for (_iter46 = this->pet_list_of_struct.begin(); _iter46 != this->pet_list_of_struct.end(); ++_iter46)
    {
      xfer += (*_iter46).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_list_of_bool", ::apache::thrift::protocol::T_LIST, 13);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_BOOL, static_cast<uint32_t>(this->pet_list_of_bool.size()));
    std::vector<bool> ::const_iterator _iter47;
    for (_iter47 = this->pet_list_of_bool.begin(); _iter47 != this->pet_list_of_bool.end(); ++_iter47)
    {
      xfer += oprot->writeBool((*_iter47));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_set_of_i32", ::apache::thrift::protocol::T_SET, 14);
  {
    xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->pet_set_of_i32.size()));
    std::set<int32_t> ::const_iterator _iter48;
    for (_iter48 = this->pet_set_of_i32.begin(); _iter48 != this->pet_set_of_i32.end(); ++_iter48)
    {
      xfer += oprot->writeI32((*_iter48));
    }
    xfer += oprot->writeSetEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_set_of_struct", ::apache::thrift::protocol::T_SET, 15);
  {
    xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->pet_set_of_struct.size()));
    std::set<EmbeddedStruct> ::const_iterator _iter49;
    for (_iter49 = this->pet_set_of_struct.begin(); _iter49 != this->pet_set_of_struct.end(); ++_iter49)
    {
      xfer += (*_iter49).write(oprot);
    }
    xfer += oprot->writeSetEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_map_i32_string", ::apache::thrift::protocol::T_MAP, 16);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->pet_map_i32_string.size()));
    std::map<int32_t, std::string> ::const_iterator _iter50;
    for (_iter50 = this->pet_map_i32_string.begin(); _iter50 != this->pet_map_i32_string.end(); ++_iter50)
    {
      xfer += oprot->writeI32(_iter50->first);
      xfer += oprot->writeString(_iter50->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("pet_map_string_struct", ::apache::thrift::protocol::T_MAP, 17);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_STRING, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->pet_map_string_struct.size()));
    std::map<std::string, EmbeddedStruct> ::const_iterator _iter51;
    for (_iter51 = this->pet_map_string_struct.begin(); _iter51 != this->pet_map_string_struct.end(); ++_iter51)
    {
      xfer += oprot->writeString(_iter51->first);
      xfer += _iter51->second.write(oprot);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ResponseData &a, ResponseData &b) {
  using ::std::swap;
  swap(a.pet_id, b.pet_id);
  swap(a.pet_name, b.pet_name);
  swap(a.pet_weight, b.pet_weight);
  swap(a.pet_i8_value, b.pet_i8_value);
  swap(a.pet_i16_value, b.pet_i16_value);
  swap(a.pet_i64_value, b.pet_i64_value);
  swap(a.pet_double_value, b.pet_double_value);
  swap(a.pet_bool_value, b.pet_bool_value);
  swap(a.pet_binary_value, b.pet_binary_value);
  swap(a.pet_embedded_struct, b.pet_embedded_struct);
  swap(a.pet_list_i32, b.pet_list_i32);
  swap(a.pet_list_of_struct, b.pet_list_of_struct);
  swap(a.pet_list_of_bool, b.pet_list_of_bool);
  swap(a.pet_set_of_i32, b.pet_set_of_i32);
  swap(a.pet_set_of_struct, b.pet_set_of_struct);
  swap(a.pet_map_i32_string, b.pet_map_i32_string);
  swap(a.pet_map_string_struct, b.pet_map_string_struct);
  swap(a.__isset, b.__isset);
}

ResponseData::ResponseData(const ResponseData& other52) {
  pet_id = other52.pet_id;
  pet_name = other52.pet_name;
  pet_weight = other52.pet_weight;
  pet_i8_value = other52.pet_i8_value;
  pet_i16_value = other52.pet_i16_value;
  pet_i64_value = other52.pet_i64_value;
  pet_double_value = other52.pet_double_value;
  pet_bool_value = other52.pet_bool_value;
  pet_binary_value = other52.pet_binary_value;
  pet_embedded_struct = other52.pet_embedded_struct;
  pet_list_i32 = other52.pet_list_i32;
  pet_list_of_struct = other52.pet_list_of_struct;
  pet_list_of_bool = other52.pet_list_of_bool;
  pet_set_of_i32 = other52.pet_set_of_i32;
  pet_set_of_struct = other52.pet_set_of_struct;
  pet_map_i32_string = other52.pet_map_i32_string;
  pet_map_string_struct = other52.pet_map_string_struct;
  __isset = other52.__isset;
}
ResponseData& ResponseData::operator=(const ResponseData& other53) {
  pet_id = other53.pet_id;
  pet_name = other53.pet_name;
  pet_weight = other53.pet_weight;
  pet_i8_value = other53.pet_i8_value;
  pet_i16_value = other53.pet_i16_value;
  pet_i64_value = other53.pet_i64_value;
  pet_double_value = other53.pet_double_value;
  pet_bool_value = other53.pet_bool_value;
  pet_binary_value = other53.pet_binary_value;
  pet_embedded_struct = other53.pet_embedded_struct;
  pet_list_i32 = other53.pet_list_i32;
  pet_list_of_struct = other53.pet_list_of_struct;
  pet_list_of_bool = other53.pet_list_of_bool;
  pet_set_of_i32 = other53.pet_set_of_i32;
  pet_set_of_struct = other53.pet_set_of_struct;
  pet_map_i32_string = other53.pet_map_i32_string;
  pet_map_string_struct = other53.pet_map_string_struct;
  __isset = other53.__isset;
  return *this;
}
void ResponseData::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ResponseData(";
  out << "pet_id=" << to_string(pet_id);
  out << ", " << "pet_name=" << to_string(pet_name);
  out << ", " << "pet_weight=" << to_string(pet_weight);
  out << ", " << "pet_i8_value=" << to_string(pet_i8_value);
  out << ", " << "pet_i16_value=" << to_string(pet_i16_value);
  out << ", " << "pet_i64_value=" << to_string(pet_i64_value);
  out << ", " << "pet_double_value=" << to_string(pet_double_value);
  out << ", " << "pet_bool_value=" << to_string(pet_bool_value);
  out << ", " << "pet_binary_value=" << to_string(pet_binary_value);
  out << ", " << "pet_embedded_struct=" << to_string(pet_embedded_struct);
  out << ", " << "pet_list_i32=" << to_string(pet_list_i32);
  out << ", " << "pet_list_of_struct=" << to_string(pet_list_of_struct);
  out << ", " << "pet_list_of_bool=" << to_string(pet_list_of_bool);
  out << ", " << "pet_set_of_i32=" << to_string(pet_set_of_i32);
  out << ", " << "pet_set_of_struct=" << to_string(pet_set_of_struct);
  out << ", " << "pet_map_i32_string=" << to_string(pet_map_i32_string);
  out << ", " << "pet_map_string_struct=" << to_string(pet_map_string_struct);
  out << ")";
}

}}}} // namespace
