/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53e3b0; label: FUN_0053e3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0053e3b0(int *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(*param_1 + 3U & 0xfffffffc);
  *param_1 = (int)piVar1;
  if (param_2 <= piVar1 + 0x13c2) {
    return (int *)0x0;
  }
  *param_1 = (int)(piVar1 + 2);
  *piVar1 = (int)(piVar1 + 2);
  *param_1 = *param_1 + 0x4f00;
  piVar1[1] = 0;
  _memset((void *)*piVar1,0,0x4f00);
  FUN_0053df20(piVar1,param_3);
  return piVar1;
}

