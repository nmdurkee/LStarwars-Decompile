/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4faf60; label: FUN_004faf60
 */

uint FUN_004faf60(uint param_1,void *param_2,size_t param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  size_t _Size;
  undefined4 *puVar8;
  size_t sVar9;
  uint local_8;
  
  iVar7 = (param_1 * 3 + -0x1800) * 0x10;
  puVar8 = (undefined4 *)
           ((*(int *)(&DAT_0297dc80 + iVar7) + 3) * 0x10 + *(int *)(&DAT_0297dc60 + iVar7));
  if (*(int *)(&DAT_0297dc88 + iVar7) == 2) {
    param_1 = 0;
    for (; param_3 != 0; param_3 = param_3 - _Size) {
      sVar9 = DAT_0090fba4;
      if (DAT_0090fba4 == 0) {
        FUN_004f6760();
        if (DAT_00917840 == DAT_0091784c) {
          _memcpy(&DAT_008cf598,&DAT_0088ab50,DAT_00917840);
        }
        else {
          FUN_004faea0(&DAT_0088ab50,&DAT_008cf598,DAT_00917840,DAT_0091784c);
        }
        DAT_008cf390 = 0;
        sVar9 = DAT_0091784c;
      }
      _Size = param_3;
      if ((int)sVar9 <= (int)param_3) {
        _Size = sVar9;
      }
      _memcpy(param_2,&DAT_008cf598 + DAT_008cf390,_Size);
      DAT_008cf390 = DAT_008cf390 + _Size;
      param_1 = param_1 + _Size;
      DAT_0090fba4 = sVar9 - _Size;
      param_2 = (void *)((int)param_2 + _Size);
    }
    return param_1;
  }
  if ((*(int *)(&DAT_0297dc70 + iVar7) != puVar8[2]) ||
     (*(int *)(&DAT_0297dc74 + iVar7) != puVar8[3])) {
    FUN_004f6de0(*puVar8,*(int *)(&DAT_0297dc70 + iVar7),*(int *)(&DAT_0297dc74 + iVar7),0);
    puVar8[2] = *(undefined4 *)(&DAT_0297dc70 + iVar7);
    puVar8[3] = *(undefined4 *)(&DAT_0297dc74 + iVar7);
  }
  uVar3 = *(uint *)(&DAT_0297dc78 + iVar7);
  uVar2 = uVar3 + *(uint *)(&DAT_0297dc68 + iVar7);
  uVar5 = uVar2 - *(uint *)(&DAT_0297dc70 + iVar7);
  iVar4 = ((((int)uVar3 >> 0x1f) + *(int *)(&DAT_0297dc6c + iVar7) +
           (uint)CARRY4(uVar3,*(uint *)(&DAT_0297dc68 + iVar7))) - *(int *)(&DAT_0297dc74 + iVar7))
          - (uint)(uVar2 < *(uint *)(&DAT_0297dc70 + iVar7));
  iVar6 = iVar4;
  local_8 = uVar5;
  if ((iVar4 < 1) && (iVar4 < 0)) {
    local_8 = 0;
    iVar6 = 0;
  }
  if ((((iVar6 < (int)param_3 >> 0x1f) || ((iVar6 <= (int)param_3 >> 0x1f && (local_8 <= param_3))))
      && (param_3 = uVar5, iVar4 < 1)) && (iVar4 < 0)) {
    param_3 = 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  uVar3 = FUN_004fb550(*puVar8,param_2,param_3);
  if (-1 < (int)uVar3) {
    puVar1 = (uint *)(&DAT_0297dc70 + iVar7);
    uVar2 = *puVar1;
    *puVar1 = *puVar1 + uVar3;
    *(uint *)(&DAT_0297dc74 + iVar7) =
         *(int *)(&DAT_0297dc74 + iVar7) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar2,uVar3);
    puVar8[2] = *(undefined4 *)(&DAT_0297dc70 + iVar7);
    puVar8[3] = *(undefined4 *)(&DAT_0297dc74 + iVar7);
  }
  return uVar3;
}

