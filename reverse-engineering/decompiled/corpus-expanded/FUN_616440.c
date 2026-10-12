/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x616440; label: FUN_00616440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00616440(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  ushort *puVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  
  piVar1 = param_1;
  if (param_1[1] != 0) {
    FUN_004ef660(&param_1,param_1[2] + param_1[1],2);
    if (*piVar1 != 0) {
      FUN_00621180(&param_1);
    }
    piVar1 = piVar1 + 2;
    *piVar1 = *piVar1 + 2;
  }
  uVar4 = param_2;
  iVar5 = (short)param_1 + 2;
  iVar2 = in_ECX + iVar5 * 0x18;
  if ((*(short *)(in_ECX + 2 + iVar5 * 0x18) == (short)param_1) &&
     (*(char *)(*(int *)(iVar2 + 8) + 0xc) != '\0')) {
    iVar5 = FUN_0060e480(iVar2,param_2);
    if (iVar5 == 1) {
      FUN_00612b10(iVar2);
      *(undefined4 *)(in_ECX + 0x38 + (short)param_1 * 0x18) = uVar4;
      puVar3 = (ushort *)(in_ECX + ((short)param_1 + 2) * 0x18);
      *puVar3 = *puVar3 | 0x20;
      FUN_0060e4c0(in_ECX + ((short)param_1 + 2) * 0x18,uVar4);
      FUN_00615720(param_1,uVar4);
    }
  }
  return;
}

