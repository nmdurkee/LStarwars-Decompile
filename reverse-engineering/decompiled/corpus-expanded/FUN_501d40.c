/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501d40; label: FUN_00501d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x00501de0) */
/* WARNING: Removing unreachable block (ram,0x00501e00) */
/* WARNING: Removing unreachable block (ram,0x00501e11) */
/* WARNING: Removing unreachable block (ram,0x00501e18) */
/* WARNING: Removing unreachable block (ram,0x00501e29) */
/* WARNING: Removing unreachable block (ram,0x00501e3d) */
/* WARNING: Removing unreachable block (ram,0x00501e47) */
/* WARNING: Removing unreachable block (ram,0x00501e59) */

void FUN_00501d40(int param_1,undefined4 param_2)

{
  int in_EAX;
  undefined1 local_a8 [164];
  
  if ((DAT_0092130c != 0) && (DAT_00921314 != (code *)0x0)) {
    if (*(int *)(in_EAX + 0x50) != 0) {
      FUN_005c9c40(*(int *)(in_EAX + 0x50),param_2,local_a8);
    }
    FUN_005010f0();
    if (-1 < *(int *)(param_1 + 4)) {
      (*DAT_00921314)(*(int *)(param_1 + 4));
    }
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  return;
}

