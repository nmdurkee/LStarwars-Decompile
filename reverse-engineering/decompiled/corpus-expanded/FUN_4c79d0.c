/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c79d0; label: FUN_004c79d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004c79d0(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *(undefined4 *)(param_1 + 0x5060) = 0;
  *(undefined4 *)(param_1 + 0x5064) = 0;
  if (*(char *)(*(int *)(param_1 + 0x128) + 0xea) != '\0') {
    uVar1 = *(int *)(param_1 + 0x104) + 3U & 0xfffffffc;
    *(uint *)(param_1 + 0x104) = uVar1;
    *(uint *)(param_1 + 0x5060) = uVar1;
    *(uint *)(param_1 + 0x104) = (uint)*(byte *)(*(int *)(param_1 + 0x128) + 0xea) * 0x94 + uVar1;
  }
  return uVar1;
}

