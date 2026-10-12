/* Ghidra analysis pseudocode, not original source.
 * ev_52657a7e1db53538daec051130af6184911435fe99c383e1c36de6367d35a487
 * Entry: 0x60e780; label: FUN_0060e780
 */

void FUN_0060e780(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x2140) == 0) {
    *(undefined4 *)(in_ECX + 0x2148) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x377c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x3788) = 0xffffffff;
    DAT_028572e0 = DAT_028fec04;
    *(int **)(in_ECX + 0x110f0) = DAT_028fec04;
    *(undefined4 *)(in_ECX + 0x2134) = 0;
    *(undefined4 *)(in_ECX + 0x2138) = 0;
    FUN_00617270();
    FUN_00612750();
    (**(code **)**(undefined4 **)(in_ECX + 0x110f0))(0);
    (**(code **)(*DAT_028572e0 + 0x28))(in_ECX + 0x216c);
    *(undefined4 *)(in_ECX + 0x2140) = 1;
    *(undefined4 *)(in_ECX + 0x2144) = 0;
    DAT_028fec20 = 1;
    FUN_00610c60(0);
    FUN_006105b0();
    return;
  }
  return;
}

