/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x491010; label: FUN_00491010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00491010(void)

{
  int iVar1;
  float fVar2;
  ushort uVar3;
  int unaff_ESI;
  float10 fVar4;
  undefined1 local_c [4];
  undefined4 local_8;
  
  FUN_0048fc80();
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  iVar1 = unaff_ESI + 0x40;
  *(undefined4 *)(unaff_ESI + 0x48) = 0x3e138ef3;
  FUN_005b3620(iVar1,iVar1,*(ushort *)(unaff_ESI + 0x88) + 0x8000);
  FUN_005b37d0(iVar1,iVar1,unaff_ESI + 0x68);
  FUN_004900e0();
  local_8 = *(undefined4 *)(unaff_ESI + 0x6c);
  fVar4 = (float10)FUN_005506f0(0,iVar1,0x3e4ccccd,0xffffffff);
  *(float *)(unaff_ESI + 0x44) = (float)fVar4;
  fVar4 = (float10)FUN_005506f0(0,local_c,0x3e4ccccd,0xffffffff);
  fVar2 = (float)fVar4;
  *(float *)(unaff_ESI + 0x50) = fVar2;
  if (fVar2 != 2e+06) {
    *(float *)(unaff_ESI + 0x50) = fVar2 + 0.005;
    FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x90,unaff_ESI + 0x92);
  }
  *(ushort *)(unaff_ESI + 0x94) = *(ushort *)(unaff_ESI + 0x94) | 0x90;
  uVar3 = *(ushort *)(unaff_ESI + 0x94);
  *(undefined2 *)(unaff_ESI + 0x8e) = 0;
  if (((uVar3 & 2) == 0) || ((uVar3 & 0x20) == 0)) {
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
    *(ushort *)(unaff_ESI + 0x94) = uVar3 & 0xefb0;
    *(undefined4 *)(unaff_ESI + 0x7c) = 0;
  }
  FUN_005b4670();
  FUN_005b4900();
  return;
}

