/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b9d90; label: FUN_005b9d90
 */

float10 FUN_005b9d90(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1 * 0x19660d + 0x3c6ef35f;
  *param_1 = uVar1;
  return (float10)((float)(uVar1 & 0x7fffff | 0x3f800000) - 1.0);
}

