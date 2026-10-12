/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x6141b0; label: FUN_006141b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006141b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int local_4;
  
  piVar2 = param_1;
  local_4 = in_ECX;
  if (param_1[1] != 0) {
    FUN_004ef660(&param_1,param_1[2] + param_1[1],2);
    if (*piVar2 != 0) {
      FUN_00621180(&param_1);
    }
    piVar2[2] = piVar2[2] + 2;
  }
  if (piVar2[1] != 0) {
    FUN_004ef660(&local_4,piVar2[2] + piVar2[1],2);
    if (*piVar2 != 0) {
      FUN_00621180(&local_4);
    }
    piVar2[2] = piVar2[2] + 2;
  }
  iVar1 = in_ECX + ((short)param_1 + 2) * 0x18;
  if ((short)param_1 == *(short *)(in_ECX + 2 + ((short)param_1 + 2) * 0x18)) {
    iVar3 = FUN_006be780(*(undefined4 *)(iVar1 + 0x10));
    if (((short)local_4 == iVar3) && (*(int *)(iVar1 + 0xc) != 0)) {
      FUN_006c63b0(*(undefined4 *)(*(int *)(iVar1 + 0x10) + 0x14),*(int *)(iVar1 + 0xc),
                   (int)(short)param_1,1);
      FUN_00612b10(iVar1);
      FUN_00611e60();
    }
  }
  return;
}

