/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x6412b0; label: FUN_006412b0
 */

uint FUN_006412b0(undefined4 param_1,uint *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *param_2 + 3 & 0xfffffffc;
  *param_2 = uVar2;
  FUN_006354a0(uVar2);
  uVar1 = FUN_00641020(param_1,uVar2);
  *(undefined4 *)(uVar2 + 0x560) = uVar1;
  DAT_0291396c = uVar2;
  *param_2 = *param_2 + 0x564;
  return uVar2;
}

