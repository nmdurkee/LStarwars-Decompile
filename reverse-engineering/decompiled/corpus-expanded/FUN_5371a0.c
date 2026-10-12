/* Ghidra pseudocode, not original source.
 * ev_b6e394b5e6447b25b30eeb5758ac1a35d86131e46c625f62ba009b62f4fc19bf
 * Entry: 0x5371a0; label: FUN_005371a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005372ab) */
/* WARNING: Removing unreachable block (ram,0x005372f1) */

void FUN_005371a0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,float param_5)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  if (((*(uint *)(param_3 + 0x1e8) & 0x2000000) == 0) &&
     ((((*(uint *)(param_2 + 0x1fc) & 4) == 0 || ((*(byte *)(param_3 + 0x166) & 1) == 0)) ||
      (*(short *)(param_2 + 0x27e) != -1)))) {
    if (*(int *)(param_3 + 0x158) == 0) {
      *(undefined4 *)(param_3 + 0x170) = *(undefined4 *)(param_2 + 0x5c);
      *(undefined4 *)(param_3 + 0x174) = *(undefined4 *)(param_2 + 0x60);
      *(undefined4 *)(param_3 + 0x178) = *(undefined4 *)(param_2 + 100);
    }
    else if ((*(uint *)(param_2 + 0x1fc) & 0x80000) == 0) {
      FUN_0052f800(param_1,param_2,param_3,DAT_00801d54,param_4);
    }
    else {
      FUN_0052f800(param_1,param_2,param_3,0,param_4);
    }
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfdffffff;
    if ((*(byte *)(param_3 + 0x166) & 1) == 0) {
      *(float *)(param_3 + 0x208) = *(float *)(param_3 + 0x208) + param_5;
      return;
    }
  }
  else {
    iVar3 = *(int *)(param_3 + 0x158);
    if ((iVar3 != 0) && (iVar4 = *(int *)(param_3 + 0x15c), iVar4 != 0)) {
      iVar5 = (uint)*(byte *)(iVar4 + 0x10) * 0x5c + *(int *)(iVar3 + 0x7c);
      iVar8 = (uint)*(byte *)(iVar4 + 0x11) * 0x5c + *(int *)(iVar3 + 0x7c);
      if ((*(char *)(iVar5 + 0x2a) != '\0') &&
         ((*(byte *)(iVar3 + 0x18 + (uint)(*(byte *)(iVar4 + 0x10) >> 3)) &
          (byte)(1 << (*(byte *)(iVar4 + 0x10) & 7))) == 0)) {
        FUN_0051af40(param_1,iVar3,iVar5);
      }
      if ((*(char *)(iVar8 + 0x2a) != '\0') &&
         (bVar2 = *(byte *)(*(int *)(param_3 + 0x15c) + 0x11),
         (*(byte *)((bVar2 >> 3) + 0x18 + *(int *)(param_3 + 0x158)) & (byte)(1 << (bVar2 & 7))) ==
         0)) {
        FUN_0051af40(param_1,*(int *)(param_3 + 0x158),iVar8);
      }
    }
    if ((*(short *)(param_3 + 0x124) != -1) && (*(int *)(param_3 + 0x158) != 0)) {
      uVar6 = (uint)*(short *)(param_3 + 0x124);
      uVar7 = uVar6 & 0x80000007;
      pbVar1 = (byte *)(((int)(uVar6 + ((int)uVar6 >> 0x1f & 7U)) >> 3) + 0x58 +
                       *(int *)(param_3 + 0x158));
      if ((int)uVar7 < 0) {
        uVar7 = (uVar7 - 1 | 0xfffffff8) + 1;
      }
      *pbVar1 = *pbVar1 | '\x01' << ((byte)uVar7 & 0x1f);
    }
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfdffffff;
  }
  *(undefined4 *)(param_3 + 0x208) = 0;
  return;
}

