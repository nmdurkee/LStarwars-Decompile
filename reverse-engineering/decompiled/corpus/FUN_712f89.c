/* Ghidra analysis pseudocode, not original source.
 * ev_9b16042430a980d3b9c0d140a3205847c036a5269f23ab8e6a7213cf146d66e1
 * Entry: 0x712f89; label: FUN_00712f89
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

