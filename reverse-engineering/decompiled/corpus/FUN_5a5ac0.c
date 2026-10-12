/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a5ac0; label: FUN_005a5ac0
 */

undefined4 FUN_005a5ac0(int param_1,undefined4 param_2,float *param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x46c0)) {
    iVar5 = 0;
    do {
      if (((iVar4 != param_4) &&
          (iVar3 = *(int *)(param_1 + 0x46bc) + iVar5, (*(uint *)(iVar3 + 200) & 0x2000300) != 0))
         && (pfVar1 = *(float **)(iVar3 + 0x58),
            fVar2 = (pfVar1[2] - param_3[2]) * (pfVar1[2] - param_3[2]) +
                    (*pfVar1 - *param_3) * (*pfVar1 - *param_3) +
                    (pfVar1[1] - param_3[1]) * (pfVar1[1] - param_3[1]),
            fVar2 < 0.0025000002 != (fVar2 == 0.0025000002))) {
        return 1;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0xd4;
    } while (iVar4 < *(int *)(param_1 + 0x46c0));
  }
  return 0;
}

