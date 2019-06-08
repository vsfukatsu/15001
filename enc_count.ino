//参考URL：https://teratail.com/questions/155843
//上記URLのソースコード2を改変
//EnPinA_01 = 3を11に、EnPinB_01 = 4を10に
//ボーレートを9600に変更

int EnPinA_01 = 14;
int EnPinB_01 = 15;
int pos_01 = 0;
void position01(int, int);

int EnPinA_02 = 16;
int EnPinB_02 = 17;
int pos_02 = 0;
void position02(int, int);

int EnPinA_03 = 18;
int EnPinB_03 = 19;
int pos_03 = 0;
void position03(int, int);

void setup()
{
    pinMode(EnPinA_01, INPUT_PULLUP);  //digitalを使う場合のみ設定
    pinMode(EnPinB_01, INPUT_PULLUP);  //同上
    pinMode(EnPinA_02, INPUT_PULLUP);  //digitalを使う場合のみ設定
    pinMode(EnPinB_02, INPUT_PULLUP);  //同上
    pinMode(EnPinA_03, INPUT_PULLUP);  //digitalを使う場合のみ設定
    pinMode(EnPinB_03, INPUT_PULLUP);  //同上
    Serial.begin(9600);
    Serial.print("pos_01 : ");
    Serial.println(pos_01);
    Serial.print("pos_02 : ");
    Serial.println(pos_02);
    Serial.print("pos_03 : ");
    Serial.println(pos_03);
}

void loop()
{
    int a_01 = 0;
    int b_01 = 0;
    int a_02 = 0;
    int b_02 = 0;
    int a_03 = 0;
    int b_03 = 0;
    a_01 = digitalRead(EnPinA_01);
    b_01 = digitalRead(EnPinB_01);
    position01(a_01, b_01);
    a_02 = digitalRead(EnPinA_02);
    b_02 = digitalRead(EnPinB_02);
    position02(a_02, b_02);
    a_03 = digitalRead(EnPinA_03);
    b_03 = digitalRead(EnPinB_03);
    position03(a_03, b_03);
}

void position01(int A, int B)
{
    static int bA = 1;
    static int bB = 1;
    static int bpos = 0;

    if((bA == A) && (bB == B))
    {
        // 何もしない
    }
    else
    {
        // bAbB == 00 or 11
        if(bA == bB)
        {
            if((bA != A) && (bB == B))
            {
                pos_01++;    // 右
            }
            else if((bA == A) && (bB != B))
            {
                pos_01--;    // 左
            }
        }
        // bAbB == 01 or 10
        else
        {
            if((bA != A) && (bB == B))
            {
                pos_01--;    // 左
            }
            else if((bA == A) && (bB != B))
            {
                pos_01++;    // 右
            }
        }

        if(bpos != pos_01)
        {
            Serial.print("pos_01 : ");
            Serial.print(pos_01);
            if(bpos < pos_01)
            {
                Serial.println(" →");
            }
            else
            {
                Serial.println(" ←");
            }
            bpos = pos_01;
        }
        bA = A;
        bB = B;
    }
}

void position02(int A, int B)
{
    static int bA = 1;
    static int bB = 1;
    static int bpos_02 = 0;

    if((bA == A) && (bB == B))
    {
        // 何もしない
    }
    else
    {
        // bAbB == 00 or 11
        if(bA == bB)
        {
            if((bA != A) && (bB == B))
            {
                pos_02++;    // 右
            }
            else if((bA == A) && (bB != B))
            {
                pos_02--;    // 左
            }
        }
        // bAbB == 01 or 10
        else
        {
            if((bA != A) && (bB == B))
            {
                pos_02--;    // 左
            }
            else if((bA == A) && (bB != B))
            {
                pos_02++;    // 右
            }
        }

        if(bpos_02 != pos_02)
        {
            Serial.print("pos_02 : ");
            Serial.print(pos_02);
            if(bpos_02 < pos_02)
            {
                Serial.println(" →");
            }
            else
            {
                Serial.println(" ←");
            }
            bpos_02 = pos_02;
        }
        bA = A;
        bB = B;
    }
}

void position03(int A, int B)
{
    static int bA = 1;
    static int bB = 1;
    static int bpos_03 = 0;

    if((bA == A) && (bB == B))
    {
        // 何もしない
    }
    else
    {
        // bAbB == 00 or 11
        if(bA == bB)
        {
            if((bA != A) && (bB == B))
            {
                pos_03++;    // 右
            }
            else if((bA == A) && (bB != B))
            {
                pos_03--;    // 左
            }
        }
        // bAbB == 01 or 10
        else
        {
            if((bA != A) && (bB == B))
            {
                pos_03--;    // 左
            }
            else if((bA == A) && (bB != B))
            {
                pos_03++;    // 右
            }
        }

        if(bpos_03 != pos_03)
        {
            Serial.print("pos_03 : ");
            Serial.print(pos_03);
            if(bpos_03 < pos_03)
            {
                Serial.println(" →");
            }
            else
            {
                Serial.println(" ←");
            }
            bpos_03 = pos_03;
        }
        bA = A;
        bB = B;
    }
}
