/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x4557e0; label: FUN_004557e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004557e0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  float10 fVar7;
  float10 fVar8;
  float local_30;
  undefined4 local_2c;
  float local_28;
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  iVar4 = 0;
  iVar6 = 0;
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar6 = *piVar2;
  }
  if ((param_6 != 0) && (0 < param_5)) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"locator=");
      if (iVar3 == 0) {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"randxz=");
        if (iVar3 != 0) {
          fVar7 = (float10)FUN_005147c0(param_2,iVar3 + 7);
          *(float *)(param_2 + 0x70) = (float)fVar7;
        }
      }
      else {
        iVar3 = FUN_0051ac10(param_1,iVar3 + 8);
        if (iVar3 != 0) {
          *(undefined4 *)(param_2 + 0x78) = *(undefined4 *)(iVar3 + 0x10);
          *(undefined4 *)(param_2 + 0x7c) = *(undefined4 *)(iVar3 + 0x14);
          *(undefined4 *)(param_2 + 0x80) = *(undefined4 *)(iVar3 + 0x18);
          *(undefined1 *)(param_2 + 0x68) = 1;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
  }
  if ((iVar6 != 0) && (*(char *)(param_2 + 0x68) != '\0')) {
    FUN_004a24d0(iVar6,local_18,local_c);
    local_30 = *(float *)(param_2 + 0x78);
    local_2c = *(undefined4 *)(param_2 + 0x7c);
    local_28 = *(float *)(param_2 + 0x80);
    if (0.0 < *(float *)(param_2 + 0x70)) {
      fVar1 = *(float *)(param_2 + 0x70);
      fVar7 = (float10)FUN_005b9dd0();
      fVar8 = (float10)fVar1;
      local_30 = (float)((fVar8 - (fVar8 + fVar8) * fVar7) + (float10)local_30);
      fVar1 = *(float *)(param_2 + 0x70);
      fVar7 = (float10)FUN_005b9dd0();
      fVar8 = (float10)fVar1;
      local_28 = (float)((fVar8 - (fVar8 + fVar8) * fVar7) + (float10)local_28);
    }
    puVar5 = local_18;
    iVar6 = 2;
    do {
      if (*(float *)(puVar5 + 4) != 1e+09) {
        fVar7 = (float10)FUN_005becc0(&local_30,puVar5,local_24);
        FUN_006018c0(DAT_0087b8d8,_DAT_007fbfd8,_DAT_007fbfe0,_DAT_007fbfe8,puVar5,local_24,
                     DAT_007fbff8,_DAT_007fbff0,(float)fVar7);
        FUN_00681f40("ForceLightningLp",param_2 + 0x78);
      }
      puVar5 = puVar5 + 0xc;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    *(int *)(param_3 + 0x1e4) = param_2 + 0x78;
  }
  return 0;
}

