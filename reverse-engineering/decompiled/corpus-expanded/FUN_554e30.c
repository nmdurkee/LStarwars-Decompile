/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554e30; label: FUN_00554e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00554e30(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  undefined4 local_4;
  
  sVar1 = FUN_006e6b90();
  *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xfffffcff;
  local_4 = 0;
  if ((*(uint *)(param_1 + 0x84) & 0x20) != 0) {
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xffffffdf;
    goto LAB_00554f27;
  }
  iVar2 = FUN_005a0f10(*(undefined4 *)(param_1 + 0x68));
  iVar3 = *(int *)(param_1 + 0x68);
  bVar5 = *(int *)(iVar3 + 0xc) != 2;
  uVar4 = *(uint *)(param_1 + 0x84);
  if (param_2 == 0x1e) {
    if ((uVar4 & 4) != 0) {
      if (iVar2 != 0) goto LAB_00554ed0;
      if ((bVar5) || ((uVar4 & 0x400) == 0)) goto LAB_00554ed6;
      bVar5 = true;
LAB_00554efb:
      *(uint *)(param_1 + 0x84) = uVar4 & 0xffffffbf;
      if ((uVar4 & 2) == 0) goto LAB_00554fad;
LAB_00554f0d:
      uVar4 = uVar4 & 0xffffffbf | 0x100;
LAB_00554f13:
      *(uint *)(param_1 + 0x84) = uVar4;
      if (bVar5) {
        param_2 = -1;
      }
      goto LAB_00554f27;
    }
    if (!bVar5) {
LAB_00554ed0:
      if (*(char *)(iVar3 + 8) != '\0') {
        bVar5 = false;
        goto LAB_00554efb;
      }
    }
LAB_00554ed6:
    if ((uVar4 & 2) == 0) {
      *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) - sVar1;
    }
    else {
      *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + sVar1;
    }
  }
  else {
    if ((uVar4 & 4) == 0) {
      if (iVar2 == 0) {
        if ((bVar5) || ((uVar4 & 0x400) == 0)) goto LAB_00554f58;
        bVar5 = true;
      }
      else {
LAB_00554f52:
        if (*(char *)(iVar3 + 8) == '\0') goto LAB_00554f58;
        bVar5 = false;
      }
      *(uint *)(param_1 + 0x84) = uVar4 & 0xffffffbf;
      if ((uVar4 & 2) == 0) goto LAB_00554f0d;
LAB_00554fad:
      uVar4 = uVar4 & 0xffffffbf | 0x200;
      goto LAB_00554f13;
    }
    if (!bVar5) goto LAB_00554f52;
LAB_00554f58:
    if ((uVar4 & 2) == 0) {
      *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + sVar1;
    }
    else {
      *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) - sVar1;
    }
  }
  *(uint *)(param_1 + 0x84) = uVar4 | 0x40;
  local_4 = 1;
LAB_00554f27:
  iVar3 = FUN_00550040(*(undefined2 *)(param_1 + 0x7c),*(undefined2 *)(param_1 + 0x80));
  if (iVar3 < 0) {
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) | 1;
  }
  else {
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & 0xfffffffe;
  }
  *(undefined2 *)(param_1 + 0x7e) = *(undefined2 *)(param_1 + 0x7c);
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined2 *)(param_1 + 0x80) = *(undefined2 *)(param_1 + 0x7c);
  *(undefined1 *)(param_1 + 0x89) = (undefined1)param_2;
  return local_4;
}

