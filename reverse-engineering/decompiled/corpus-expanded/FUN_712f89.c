/* Ghidra pseudocode, not original source.
 * ev_b8791f68223111733f427ad79b5f4124aba9c2a357a1adb651c9b460912be2bf
 * Entry: 0x712f89; label: FUN_00712f89
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00712f89(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return 0x16;
  }
  *param_1 = DAT_0297cc64;
  return 0;
}

