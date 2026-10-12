/* Ghidra analysis pseudocode, not original source.
 * ev_25f1bb0fd3b13d30151a1bfb26bccad5e839f981975d2103181562bea11eb120
 * Entry: 0x501d40; label: FUN_00501d40
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

