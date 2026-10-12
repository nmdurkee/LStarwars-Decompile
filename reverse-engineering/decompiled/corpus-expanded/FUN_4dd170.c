/* Ghidra pseudocode, not original source.
 * ev_7fb001446c14d370af68fb4a523bbd62db36fda0486cbdd4cf52041e7ba87b14
 * Entry: 0x4dd170; label: FUN_004dd170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004dd170(void)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = DAT_00882a8c;
  if (DAT_00951b50 == 0) {
    if ((((DAT_00882a8c == 0) || (DAT_00882a90 == 0)) || (*(float *)(DAT_00882a90 + 0x28) != 0.0))
       || (DAT_00882a94 == 0)) {
      FUN_004ba2d0();
      return;
    }
    uVar2 = FUN_006e6b90();
    *(undefined1 *)(iVar1 + 0x107f) = uVar2;
    *(undefined1 *)(iVar1 + 0x107e) = 3;
    FUN_004ba2d0(iVar1);
  }
  return;
}

