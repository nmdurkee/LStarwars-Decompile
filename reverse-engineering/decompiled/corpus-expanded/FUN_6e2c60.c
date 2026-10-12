/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e2c60; label: FUN_006e2c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006e2c60(void)

{
  int *piVar1;
  int *in_ECX;
  
  if (in_ECX[0x187] != 0) {
    FUN_006e85b0(in_ECX[0x187]);
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

