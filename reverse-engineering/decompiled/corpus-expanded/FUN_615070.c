/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x615070; label: FUN_00615070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615070(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_11;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  int local_4;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    FUN_0053d5d0(0x20);
    local_11 = 10;
    if (local_c != 0) {
      FUN_004ef660(local_4 + local_c,&local_11,1);
      local_4 = local_4 + 1;
    }
    uVar3 = 3;
    iVar2 = local_c;
    if (local_c == 0) {
      FUN_0060f2d0(local_10,0,local_8,local_4,3);
    }
    else {
      *(int *)(local_c + 0x4b0) = *(int *)(local_c + 0x4b0) + 1;
    }
    FUN_0060f190(local_10,iVar2,local_8,local_4,uVar3);
    puVar1 = (undefined4 *)(in_ECX + 0xd844);
    iVar2 = 8;
    do {
      if (puVar1[-3] != 0) {
        puVar1[1] = 0;
        *puVar1 = 0;
      }
      puVar1 = puVar1 + 5;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (local_c != 0) {
      if (1 < *(uint *)(local_c + 0x4b0)) {
        *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
        return;
      }
      *(undefined4 *)(local_c + 0x4b0) = 0;
    }
  }
  return;
}

