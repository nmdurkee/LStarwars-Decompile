/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x442820; label: FUN_00442820
 */

float10 FUN_00442820(undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
     (*(int **)(param_3 + 0xe4) != (int *)0x0)) {
    iVar2 = **(int **)(param_3 + 0xd0);
    iVar3 = **(int **)(param_3 + 0xe4);
    cVar1 = *(char *)(iVar3 + 0x671);
    if ((cVar1 != -1) && (cVar1 == *(char *)(iVar2 + 0x671))) {
      fVar4 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar3 + 0x670);
      fVar5 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar2 + 0x670);
      return (float10)(float)((float10)(double)fVar4 - fVar5);
    }
  }
  return (float10)0;
}

