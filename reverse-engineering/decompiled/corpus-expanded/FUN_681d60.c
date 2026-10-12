/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x681d60; label: FUN_00681d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00681d60(void *param_1)

{
  ushort *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)((int)param_1 + 200);
  _memset(param_1,0,200);
  for (; puVar3 != (undefined4 *)0x0; puVar3 = puVar3 + 1) {
    iVar2 = FUN_00650dc0(*puVar3);
    puVar1 = (ushort *)((int)param_1 + (iVar2 >> 4) * 2);
    *puVar1 = *puVar1 | (ushort)(1 << ((byte)iVar2 & 0xf));
  }
  return;
}

