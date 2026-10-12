/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440150; label: FUN_00440150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00440150(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  float10 fVar5;
  float10 fVar6;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if ((*(byte *)(param_1 + 0x1f8) & 5) != 0) {
    return 0;
  }
  iVar1 = param_1 + 0x80;
  fVar5 = (float10)FUN_005b3c50(param_2 + 0x80,iVar1,local_18);
  fVar6 = (float10)FUN_005c0240((float)fVar5);
  if ((float)fVar6 == 0.0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = 1.0 / (float)fVar6;
  }
  FUN_005b3830(local_c,local_18,fVar2);
  piVar4 = &DAT_0093d7f0;
  do {
    iVar3 = *piVar4;
    if ((((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 1) != 0)) &&
        ((*(uint *)(iVar3 + 0x1fc) & 0x1000) != 0)) && ((iVar3 != param_1 && (iVar3 != param_2)))) {
      fVar6 = (float10)FUN_005b3c50(iVar1,iVar3 + 0x80,local_18);
      if (fVar6 < (float10)(float)fVar5) {
        fVar2 = *(float *)(*piVar4 + 0x1dc) + 0.125;
        iVar3 = FUN_00551730(iVar1,local_c,*piVar4 + 0x80,fVar2 * fVar2,0);
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
    piVar4 = piVar4 + 1;
  } while ((int)piVar4 < 0x93d810);
  return 0;
}

