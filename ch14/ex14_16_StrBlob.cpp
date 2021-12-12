#include "ex14_16_StrBlob.h"

// =========================================
//
//          StrBlob operators
//
// =========================================

bool operator==(const StrBlob& lhs, const StrBlob&  rhs)
{
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
    return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(),
                                        rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !(lhs > rhs) ;   
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !( lhs < rhs);
}


// =========================================
//
//          StrBlobPtr operators
//
// =========================================



bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr > rhs.curr;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr <= rhs.curr;
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return lhs.curr >= rhs.curr;
}









//====================================================
//
//
//
//    copy assignment operator and move assignment operator
//
//
//
//====================================================

StrBlob& StrBlob::operator=(const StrBlob& lhs)
{
    data = make_shared<vector<string>>(*lhs.data);
    return *this;
}

StrBlob& StrBlob::operator=(StrBlob&& rhs) noexcept
{
    if(this != &rhs)
    {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }
    return *this;
}

//======================================
//
//      members
//
//======================================

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}
