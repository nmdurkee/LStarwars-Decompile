/* Ghidra pseudocode, not original source.
 * ev_dd26b1472d11f86911997a5210ef83804c7265178bcab9b4c8b40141cd7b855f
 * Entry: 0x4d2f90; label: FUN_004d2f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d2f90(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  short sVar4;
  byte bVar5;
  float10 fVar6;
  float10 fVar7;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  if ((param_1 != 0) && (param_2 != 0)) {
    bVar5 = *(byte *)(param_2 + 1) & 8;
    if ((bVar5 == 0) || (*(float *)(param_2 + 0xc) != 0.0)) {
      if (bVar5 != 0) {
        if (0.2 <= *(float *)(param_2 + 0xc)) {
          if (bVar5 != 0) {
            *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) & 0xe7;
            *(undefined4 *)(param_2 + 0x78) = DAT_0093b0cc;
            *(undefined4 *)(param_2 + 0x7c) = DAT_0093b0d0;
            *(undefined4 *)(param_2 + 0x80) = DAT_0093b0d4;
          }
        }
        else {
          *(float *)(param_2 + 0xc) = *(float *)(param_2 + 0xc) + _DAT_00925018;
        }
      }
    }
    else {
      iVar2 = param_1 + 0xa0;
      iVar1 = param_2 + 0x78;
      FUN_005b3920(local_4c,iVar1,iVar2);
      FUN_005b3b30(local_4c,local_4c);
      FUN_005b44e0(local_40);
      fVar6 = (float10)FUN_005bec80(iVar2);
      fVar7 = (float10)FUN_005bec80(iVar1);
      fVar6 = (float10)FUN_005b39e0(iVar1,iVar2,(float)(fVar7 * (float10)(double)fVar6));
      fVar6 = (float10)FUN_004d1ea0((float)fVar6);
      sVar4 = FUN_004d1ee0((float)fVar6);
      FUN_005b4770(local_40,(0x4000 - (short)(0x4000 - sVar4)) * 2,local_4c);
      FUN_005b3200(iVar2,iVar2,local_40);
      FUN_005b3830(iVar2,iVar2,0x3f4ccccd);
      *(float *)(param_1 + 0xcc) = *(float *)(param_1 + 0xcc) * 0.8;
      FUN_00684be0(*(undefined4 *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x58c),
                   param_1 + 0x88,0x3c,_DAT_00925018,0,0,0);
      fVar3 = *(float *)(param_2 + 0xc) + _DAT_00925018;
      *(byte *)(param_2 + 1) = *(byte *)(param_2 + 1) | 0x10;
      *(float *)(param_2 + 0xc) = fVar3;
    }
    *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 200) + 0.0001;
  }
  return;
}

