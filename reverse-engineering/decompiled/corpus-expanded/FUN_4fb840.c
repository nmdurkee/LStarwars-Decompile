/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fb840; label: FUN_004fb840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004fb887) */

int FUN_004fb840(undefined4 param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  iVar3 = DAT_00800464;
  DAT_00800464 = DAT_00800464 + 1;
  lVar5 = FUN_004f6d10(param_1);
  if (1 < iVar3) {
    iVar4 = iVar3 * 0x10;
    uVar2 = *(uint *)(iVar4 + 0x90ff9c);
    if (CONCAT44(((int)uVar2 >> 0x1f) + *(int *)(iVar4 + 0x90ffa4) +
                 (uint)CARRY4(uVar2,*(uint *)(iVar4 + 0x90ffa0)),uVar2 + *(uint *)(iVar4 + 0x90ffa0)
                ) <= lVar5) {
      DAT_00800464 = DAT_00800464 + -1;
      return 0;
    }
  }
  uVar6 = FUN_004f6d10(param_1);
  piVar1 = (int *)(iVar3 * 0x10 + 0x90ffa8);
  *(undefined8 *)(&DAT_0090ffb0 + iVar3 * 4) = uVar6;
  FUN_004fb550(param_1,piVar1,8);
  if ((int)(&DAT_0090ffac)[iVar3 * 4] < 0) {
    (&DAT_0090ffac)[iVar3 * 4] = -(&DAT_0090ffac)[iVar3 * 4];
  }
  if ((param_2 != 0) && (param_2 != *piVar1)) {
    FUN_004ef790();
  }
  return *piVar1;
}

