/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x472b80; label: FUN_00472b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00472b80(void)

{
  int iVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  char local_10;
  undefined1 local_c [4];
  undefined4 local_8;
  
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  *(undefined4 *)(unaff_ESI + 100) = 0;
  iVar1 = unaff_ESI + 100;
  *(undefined4 *)(unaff_ESI + 0x6c) = 0x3e138ef3;
  FUN_005b3620(iVar1,iVar1,*(ushort *)(unaff_ESI + 0x5c) + 0x8000);
  FUN_005b37d0(iVar1,iVar1,unaff_ESI + 0x50);
  FUN_00472800();
  local_8 = *(undefined4 *)(unaff_ESI + 0x54);
  fVar3 = (float10)FUN_005506f0(0,iVar1,0x3f800000,0xffffffff);
  *(float *)(unaff_ESI + 0x68) = (float)fVar3;
  fVar3 = (float10)FUN_005506f0(0,local_c,0x3f800000,0xffffffff);
  fVar2 = (float)fVar3;
  *(float *)(unaff_ESI + 0x74) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(unaff_ESI + 0x74) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x7c,unaff_ESI + 0x7e);
  }
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(byte *)(unaff_ESI + 99) = *(byte *)(unaff_ESI + 99) & 0xfc | 0xc;
  *(undefined1 *)(unaff_ESI + 0x60) = 0;
  if (*(char *)(unaff_ESI + 0x61) == 'r') {
    *(undefined1 *)(unaff_ESI + 0x62) = 0x22;
  }
  else {
    *(char *)(unaff_ESI + 0x62) = (*(char *)(unaff_ESI + 0x61) == 'o') + ' ';
  }
  if (*(char *)(unaff_ESI + 0x5e) == '\0') {
    fVar3 = (float10)FUN_005b9ef0(&DAT_00802538);
    local_10 = (char)(int)ROUND(fVar3 * (float10)-4.0);
    *(char *)(unaff_ESI + 0x5f) = '\x01' - local_10;
  }
  else {
    *(char *)(unaff_ESI + 0x5f) = *(char *)(unaff_ESI + 0x5e);
  }
  FUN_005b4670();
  FUN_005b4900();
  return;
}

