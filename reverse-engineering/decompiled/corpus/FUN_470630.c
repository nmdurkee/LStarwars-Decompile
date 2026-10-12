/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x470630; label: FUN_00470630
 */

undefined4 FUN_00470630(void)

{
  float fVar1;
  undefined4 *in_EAX;
  uint uVar2;
  int unaff_ESI;
  float10 fVar3;
  undefined4 local_c;
  float local_8;
  undefined4 local_4;
  
  local_c = *in_EAX;
  local_8 = (float)in_EAX[1] + 0.25;
  local_4 = in_EAX[2];
  if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b224) {
    FUN_0067a6d0();
  }
  fVar3 = (float10)FUN_005506f0(0,&local_c,0x40a00000,0xffffffff);
  fVar1 = (float)fVar3;
  if (fVar1 != 2e+06) {
    uVar2 = FUN_0067a600();
    if ((uVar2 < 0x20) && ((*(uint *)(&DAT_008034cc + uVar2 * 0xc) & 0x200) != 0)) {
      *(float *)(unaff_ESI + 0x540) = fVar1;
      FUN_0054fec0(&DAT_0292fdb8,unaff_ESI + 0x548,unaff_ESI + 0x54a);
      if (((&DAT_008034cc)[uVar2 * 0xc] & 2) != 0) {
        *(float *)(unaff_ESI + 0x54c) = fVar1;
        return 1;
      }
      *(undefined4 *)(unaff_ESI + 0x54c) = 0x49f42400;
      return 1;
    }
  }
  return 0;
}

