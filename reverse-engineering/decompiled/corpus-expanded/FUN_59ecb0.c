/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59ecb0; label: FUN_0059ecb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059ecb0(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = (undefined1 *)FUN_00559610(DAT_00956418,DAT_0095641c,4);
  uVar1 = DAT_009562c0;
  if (puVar2 != (undefined1 *)0x0) {
    *puVar2 = (undefined1)DAT_00956344;
    puVar2[1] = uVar1;
  }
  return;
}

