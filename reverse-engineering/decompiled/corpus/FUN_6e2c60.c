/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e2c60; label: FUN_006e2c60
 */

void FUN_006e2c60(void)

{
  int *piVar1;
  int *in_ECX;
  
  if ((void *)in_ECX[0x187] != (void *)0x0) {
    _free((void *)in_ECX[0x187]);
    in_ECX[0x187] = 0;
  }
  FUN_006e2170();
  piVar1 = (int *)in_ECX[0x1a3];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x1a3] = 0;
  }
  piVar1 = (int *)in_ECX[0x1ab];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x1ab] = 0;
  }
  piVar1 = (int *)in_ECX[1];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[1] = 0;
  }
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *in_ECX = 0;
  }
  return;
}

