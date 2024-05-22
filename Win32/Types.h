#pragma once
namespace Types
{
    //현재 스테이지
    enum Stage
    {
        STAGE1 = 1, //4
        STAGE2 = 2,//8
        STAGE3 = 3,//6
        STAGE4 = 4,
    };

    //면 종류
    enum Noodle
    {
        FLAT = 0, //납작면
        MIDDLE = 1, //중면
        SMALL = 2,//소면
    };

    //육수 종류
    enum Soup
    {
        MAULCHI = 3,//멸치
        TZUYU = 4,//쯔유
        DASIMA = 5,//다시마
        MU = 6,//무
    };

    //고명 종류
    enum Decoration
    {
        GATHOBUSI = 7,//"가쓰오부시"
        BANDALAMUK,//"반달어묵"
        FRYGARU,//"튀김가루"
        DAEPA,//"대파"
        PYOGO,//"표고버섯"
        FIREMEET,//"직화고기"
        YUBU,//"썬유부"
        SUKK,//"쑥갓"
        SUNKIM,//"썬김(김채)"
        FLATAMUK,//"납작어묵"
        SHRIMP,//"새우튀김"
        SUNDAEPA,//"썬대파"
        CHOUNGYANGGOCHU = 19,//"썬청양고추"
        SICHIME = 20
    };
    enum Basket
    {
        BASKET = 31,//바구니
    };

};
