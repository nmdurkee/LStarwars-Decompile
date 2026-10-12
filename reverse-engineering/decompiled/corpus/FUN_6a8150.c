/* Ghidra analysis pseudocode, not original source.
 * ev_411dd83ba30300d5831318e5e0d5db9024421d970d639e52cbaaaf14146f88dc
 * Entry: 0x6a8150; label: FUN_006a8150
 */

void FUN_006a8150(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  fVar7 = (float10)FUN_006e92e0();
  FUN_006eafc0((double)fVar7);
  iVar3 = FUN_006e6b90();
  while( true ) {
    while( true ) {
      iVar4 = 1;
      iVar5 = 1;
      if (0 < iVar1) {
        iVar6 = iVar1;
        do {
          iVar4 = iVar4 * iVar3;
          iVar5 = iVar5 * (iVar3 + 1);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      if (iVar4 <= iVar2) break;
      iVar3 = iVar3 + -1;
    }
    if (iVar2 < iVar5) break;
    iVar3 = iVar3 + 1;
  }
  return;
}

