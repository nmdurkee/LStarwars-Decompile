/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8d70; label: FUN_004d8d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d8d70(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  if (DAT_00882406 != -1) {
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)DAT_00882406,unaff_ESI + 1);
  }
  if (DAT_00882408 != -1) {
    FUN_0064b370(DAT_00882408,unaff_ESI + 1,1);
  }
  FUN_00549f10();
  FUN_00549bb0(0,0x3f400000,0x3f800000,0x3f800000);
  FUN_00681f40("Explode1",unaff_EDI + 0x80);
  FUN_004ab5a0();
  puVar2 = unaff_ESI + -0x220735;
  uVar1 = ~(1 << (((char)((int)puVar2 / 0x1c) + (char)((int)puVar2 >> 0x1f)) -
                  (char)((longlong)(int)puVar2 * 0x92492493 >> 0x3f) & 0x1fU));
  _DAT_00882a48 = _DAT_00882a48 & uVar1;
  _DAT_00882a4c = _DAT_00882a4c & (int)uVar1 >> 0x1f;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  _DAT_008827e4 = _DAT_008827e4 + -1;
  return;
}

