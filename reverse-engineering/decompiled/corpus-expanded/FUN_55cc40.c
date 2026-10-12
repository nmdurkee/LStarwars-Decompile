/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55cc40; label: FUN_0055cc40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055cc40(int param_1)

{
  char cVar1;
  int iVar2;
  float fVar3;
  
  if ((*(char *)(param_1 + 0x1079) != '\0') && (*(float *)(param_1 + 0xd30) == 1.0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    cVar1 = *(char *)(iVar2 + 0x10d);
    if ((cVar1 != -1) &&
       ((*(int *)(*(int *)(param_1 + 0x50) + 0x14 + cVar1 * 4) != 0 &&
        (*(char *)(param_1 + 0x28c) != '\0')))) {
      fVar3 = *(float *)(iVar2 + 0x4c) * *(float *)(param_1 + 0xff8);
      *(float *)(param_1 + 0x1e0) = fVar3;
      *(float *)(param_1 + 0x1dc) = fVar3;
      goto LAB_0055ccbb;
    }
  }
  *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(param_1 + 0x1e0) = *(undefined4 *)(param_1 + 0xb0);
LAB_0055ccbb:
  if (DAT_0093d508 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0055ccc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0093d508)();
    return;
  }
  return;
}

