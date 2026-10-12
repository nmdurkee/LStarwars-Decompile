/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x659dc0; label: FUN_00659dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00659dc0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_02962010;
  if ((DAT_02923194 != -1) && (DAT_02962010 != -1)) {
    uVar2 = FUN_006e6b90();
    (&DAT_0292fe28)[iVar1 * 0xb5] = uVar2;
  }
  return;
}

