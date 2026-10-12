/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4b9090; label: FUN_004b9090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b9090(void)

{
  undefined4 uVar1;
  
  FUN_004b9040();
  uVar1 = FUN_006e6b90();
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_0088096c * 4),0,_DAT_007fc2ac,0x3f800000,
               _DAT_007fc2b0,_DAT_007fc2b0,_DAT_007fc2b0,0,0xff,0xff,0xff,0x3fc00000,1,0,0,uVar1);
  return;
}

