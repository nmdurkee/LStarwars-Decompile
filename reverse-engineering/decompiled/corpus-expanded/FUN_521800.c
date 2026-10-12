/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521800; label: FUN_00521800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00521800(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = _DAT_00922210;
  _DAT_00922210 = 0;
  for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x383c0); iVar3 != 0;
      iVar3 = FUN_004f1460(DAT_009238e4 + 0x383c0,iVar3)) {
    if (*(int *)(DAT_009238e4 + 0x383c8) == iVar3) {
      iVar4 = (-(uint)(*(int *)(DAT_009238e4 + 0x383c8) != *(int *)(DAT_009238e4 + 0x383cc)) &
              0x81000000) - 0xffff01;
    }
    else {
      iVar4 = (*(int *)(DAT_009238e4 + 0x383cc) != iVar3) - 1;
    }
    if ((*(byte *)(iVar3 + 0x33) & 1) == 0) {
      FUN_00521240(iVar3 + 0x18,iVar3 + 0x24,(int)*(short *)(iVar3 + 0x30),iVar4);
    }
    else {
      if (*(float *)(iVar3 + 0x2c) <= *(float *)(iVar3 + 0x24)) {
        uVar1 = *(undefined4 *)(iVar3 + 0x2c);
      }
      else {
        uVar1 = *(undefined4 *)(iVar3 + 0x24);
      }
      FUN_0051f720(iVar3 + 0x18,uVar1,*(undefined4 *)(iVar3 + 0x1c),
                   *(float *)(iVar3 + 0x28) + *(float *)(iVar3 + 0x1c),iVar4,0,0x10);
    }
  }
  _DAT_00922210 = uVar2;
  return;
}

