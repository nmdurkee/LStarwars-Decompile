/* Ghidra pseudocode, not original source.
 * ev_4dde03cd79a837517a28bb41bf0bd080ad03d09c77c06073e29a0b26ddc1f284
 * Entry: 0x53ccf0; label: FUN_0053ccf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053ccf0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  DAT_009238e4 = param_1;
  _memset(&DAT_00921ef0,0,0x200);
  DAT_00921f58 = FUN_005e4d40(1);
  *(undefined4 *)(DAT_00921f58 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_00921f58 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_00921f58 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_00921f58 + 0x40) = *(uint *)(DAT_00921f58 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_00921f58 + 0x40) = *(uint *)(DAT_00921f58 + 0x40) & 0xffff3fff;
  *(undefined4 *)(DAT_00921f58 + 0x70) = 0x3f800000;
  *(uint *)(DAT_00921f58 + 0x40) = *(uint *)(DAT_00921f58 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_00921f58);
  DAT_00921f5c = FUN_005e4d40(1);
  *(undefined4 *)(DAT_00921f5c + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_00921f5c + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_00921f5c + 0x5c) = 0x3f000000;
  *(uint *)(DAT_00921f5c + 0x40) = *(uint *)(DAT_00921f5c + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_00921f5c + 0x40) = *(uint *)(DAT_00921f5c + 0x40) & 0xffff3fff;
  *(undefined4 *)(DAT_00921f5c + 0x70) = 0x3f800000;
  *(uint *)(DAT_00921f5c + 0x40) = *(uint *)(DAT_00921f5c + 0x40) & 0xfffffff2 | 2;
  FUN_005e4b00(DAT_00921f5c);
  DAT_00921f60 = FUN_005e4d00(1);
  *(undefined4 *)(DAT_00921f60 + 0x54) = 0x3f000000;
  *(undefined4 *)(DAT_00921f60 + 0x58) = 0x3f000000;
  *(undefined4 *)(DAT_00921f60 + 0x5c) = 0x3f000000;
  *(uint *)(DAT_00921f60 + 0x40) = *(uint *)(DAT_00921f60 + 0x40) & 0xffffefff | 0x2000;
  *(uint *)(DAT_00921f60 + 0x40) = *(uint *)(DAT_00921f60 + 0x40) | 0xc000;
  *(undefined4 *)(DAT_00921f60 + 0x70) = 0x3f800000;
  *(uint *)(DAT_00921f60 + 0x40) = *(uint *)(DAT_00921f60 + 0x40) & 0xfffffff0;
  FUN_005e4b00(DAT_00921f60);
  _DAT_00921f38 = 0x3c23d70a;
  DAT_00921f3c = 0;
  DAT_00921f40 = 0;
  DAT_00921f50 = DAT_00921f50 & 0xfffffb5c | 0x318;
  _DAT_00921f44 = 0;
  _DAT_00921f48 = 0;
  DAT_00921f34 = 0xffffffff;
  DAT_00921f4c = 0;
  DAT_009220ec = 0;
  _memset(&DAT_00921f6c,0,0x180);
  iVar2 = -1;
  if (DAT_009220ec < 8) {
    iVar2 = (int)DAT_009220ec;
    DAT_009220ec = DAT_009220ec + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar2 * 0x30,"AIEDITOR_PATHS");
    (&DAT_00921f8c)[iVar2 * 0xc] = FUN_00525cb0;
    (&DAT_00921f90)[iVar2 * 0xc] = FUN_0053bc50;
    (&DAT_00921f94)[iVar2 * 0xc] = FUN_005339d0;
    (&DAT_00921f98)[iVar2 * 0xc] = 0;
    sVar1 = DAT_009220ec;
  }
  else {
    sVar1 = FUN_00512850();
  }
  iVar3 = -1;
  DAT_00801c98 = iVar2;
  if (sVar1 < 8) {
    iVar3 = (int)sVar1;
    DAT_009220ec = sVar1 + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar3 * 0x30,"AIEDITOR_ROUTES");
    (&DAT_00921f8c)[iVar3 * 0xc] = 0;
    (&DAT_00921f90)[iVar3 * 0xc] = FUN_0053c7c0;
    (&DAT_00921f94)[iVar3 * 0xc] = FUN_00534110;
    (&DAT_00921f98)[iVar3 * 0xc] = 0;
    sVar1 = DAT_009220ec;
  }
  else {
    sVar1 = FUN_00512850();
  }
  iVar2 = -1;
  DAT_00801c9c = iVar3;
  if (sVar1 < 8) {
    iVar2 = (int)sVar1;
    DAT_009220ec = sVar1 + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar2 * 0x30,"AIEDITOR_AREAS");
    (&DAT_00921f8c)[iVar2 * 0xc] = FUN_00521920;
    (&DAT_00921f90)[iVar2 * 0xc] = FUN_0053a580;
    (&DAT_00921f94)[iVar2 * 0xc] = FUN_00530b30;
    (&DAT_00921f98)[iVar2 * 0xc] = 0;
    sVar1 = DAT_009220ec;
  }
  else {
    sVar1 = FUN_00512850();
  }
  iVar3 = -1;
  _DAT_00801ca4 = iVar2;
  if (sVar1 < 8) {
    iVar3 = (int)sVar1;
    DAT_009220ec = sVar1 + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar3 * 0x30,"AIEDITOR_LOCATORS");
    (&DAT_00921f8c)[iVar3 * 0xc] = FUN_00531ef0;
    (&DAT_00921f90)[iVar3 * 0xc] = FUN_0053ae80;
    (&DAT_00921f94)[iVar3 * 0xc] = FUN_005319f0;
    (&DAT_00921f98)[iVar3 * 0xc] = 0;
    sVar1 = DAT_009220ec;
  }
  else {
    sVar1 = FUN_00512850();
  }
  iVar2 = -1;
  DAT_00801ca8 = iVar3;
  if (sVar1 < 8) {
    iVar2 = (int)sVar1;
    DAT_009220ec = sVar1 + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar2 * 0x30,"AIEDITOR_CREATURES");
    (&DAT_00921f8c)[iVar2 * 0xc] = FUN_0052ae20;
    (&DAT_00921f90)[iVar2 * 0xc] = FUN_00539c10;
    (&DAT_00921f94)[iVar2 * 0xc] = FUN_0052a8f0;
    (&DAT_00921f98)[iVar2 * 0xc] = 0;
    sVar1 = DAT_009220ec;
  }
  else {
    sVar1 = FUN_00512850();
  }
  iVar3 = -1;
  DAT_00801ca0 = iVar2;
  if (sVar1 < 8) {
    iVar3 = (int)sVar1;
    DAT_009220ec = sVar1 + 1;
    FUN_004f1f10(&DAT_00921f6c + iVar3 * 0x30,"AIEDITOR_ANTINODES");
    (&DAT_00921f8c)[iVar3 * 0xc] = FUN_00528100;
    (&DAT_00921f90)[iVar3 * 0xc] = FUN_00539050;
    (&DAT_00921f94)[iVar3 * 0xc] = FUN_005342d0;
    (&DAT_00921f98)[iVar3 * 0xc] = 0;
  }
  else {
    FUN_00512850();
  }
  DAT_00801cac = iVar3;
  FUN_00522880("Permanent Block",0x40000000,0,0);
  FUN_00522880("Temporary Block",0x80000000,0,0);
  FUN_00522880("Link Obstacle",0x20000000,0,1);
  _DAT_00921f64 = *param_2;
  _DAT_00921f68 = *param_3;
  return;
}

