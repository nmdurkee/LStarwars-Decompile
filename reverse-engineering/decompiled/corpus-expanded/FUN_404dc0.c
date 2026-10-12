/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404dc0; label: FUN_00404dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00404dc0(void)

{
  short *psVar1;
  int iVar2;
  undefined1 local_40 [64];
  
  psVar1 = &DAT_00854944;
  iVar2 = 8;
  do {
    if ((*(char *)((int)psVar1 + -0x2f) != '\0') &&
       (*(char *)(*psVar1 * 0x10 + 0xe + *(int *)(PTR_DAT_00802c54 + 0x2ac0)) != '\0')) {
      FUN_005b4500(local_40,psVar1 + -0x24);
      FUN_005f33b0(*psVar1 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),local_40);
    }
    psVar1 = psVar1 + 0x5a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

