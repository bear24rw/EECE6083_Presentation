class ParkingCalc
{
   protected:
    float rate;
    float first_hour;

   public:
    void set_rate(float set);
    void set_first_hour(float set);
    void getTotal(int hours);
};
