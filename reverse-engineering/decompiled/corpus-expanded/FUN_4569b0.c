/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x4569b0; label: FUN_004569b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004569b0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float10 fVar9;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50 [3];
  float local_44 [3];
  undefined1 local_38 [8];
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = *piVar1;
    if (param_6 != 0) {
      *(uint *)(iVar2 + 0xeec) = *(uint *)(iVar2 + 0xeec) | 0x4000;
      *(uint *)(iVar2 + 0xef4) = *(uint *)(iVar2 + 0xef4) | 0x200000;
      *(undefined4 *)(iVar2 + 0xec8) = 0x3f800000;
      iVar7 = 0;
      *(undefined1 *)(iVar2 + 0x408) = 1;
      *(undefined4 *)(param_2 + 0x70) = 0x41200000;
      if (0 < param_5) {
        do {
          iVar6 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar7 * 4),"distance");
          if (iVar6 != 0) {
            fVar8 = (float10)FUN_005147c0(param_3,iVar6 + 9);
            *(float *)(param_2 + 0x70) = (float)fVar8;
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < param_5);
      }
    }
    FUN_0053f0e0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar2 + 0x670,0x41200000,local_38);
    iVar7 = *(int *)(param_3 + 0xe4);
    if ((iVar7 == 0) || (*(int *)(iVar7 + 4) == 0)) {
      *(undefined4 *)(iVar2 + 0xec8) = 0x3f800000;
      local_5c = local_30;
      local_58 = local_2c;
      local_54 = local_28;
    }
    else {
      fVar8 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar2 + 0x670);
      fVar9 = (float10)FUN_0053f7a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar7 + 0x670);
      fVar3 = (float)((float10)(double)fVar8 - fVar9) - *(float *)(param_2 + 0x70);
      fVar4 = *(float *)(param_2 + 0x70) * 0.5;
      if (fVar3 <= fVar4) {
        if (-fVar4 <= fVar3) {
          uVar5 = 0x3f800000;
        }
        else {
          uVar5 = 0x3f8ccccd;
        }
      }
      else {
        uVar5 = 0x3f666666;
      }
      *(undefined4 *)(iVar2 + 0xec8) = uVar5;
      FUN_005b3800(local_50,iVar7 + 0x5c,iVar7 + 0x678);
      FUN_005b3620(local_50,local_50,-(uint)*(ushort *)(iVar7 + 0x696));
      FUN_005b3800(local_44,iVar2 + 0x5c,iVar2 + 0x678);
      FUN_005b3620(local_44,local_44,-(uint)*(ushort *)(iVar2 + 0x696));
      local_54 = 0;
      local_58 = 0;
      local_5c = local_44[0] * 0.5 + local_50[0] * 0.5;
      FUN_005b37d0(&local_5c,&local_5c,&local_30);
    }
    FUN_0052fcb0(param_3,&local_5c,0,0,1,0);
    return 0;
  }
  return 1;
}

