/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fba60; label: thunk_FUN_005c8fc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_005c8fc0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  
  uVar1 = FUN_006056f0(0x280,0x800,1,1,4);
  *(undefined4 *)(in_ECX + 0x30) = uVar1;
  FUN_005f7cc0(uVar1,0,1);
  FUN_005f7ed0(*(undefined4 *)(in_ECX + 0x30),3,3);
  FUN_005f7cf0(*(undefined4 *)(in_ECX + 0x30),0xffffffff);
  FUN_005f7d00(*(undefined4 *)(in_ECX + 0x30),2,2,0);
  puVar4 = (undefined4 *)(in_ECX + 0x38);
  iVar3 = 2;
  do {
    uVar1 = FUN_005f7c50(*(undefined4 *)(in_ECX + 0x30),1,1,10);
    uVar1 = FUN_005f7c40(*(undefined4 *)(in_ECX + 0x30),uVar1);
    uVar1 = FUN_006056f0(uVar1);
    *puVar4 = uVar1;
    uVar1 = DAT_02854c2c;
    puVar4 = puVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = *(int *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x28) = DAT_02854c2c;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  iVar2 = FUN_005f7c90(uVar1);
  if (iVar3 < iVar2) {
    *(int *)(in_ECX + 0xc) = iVar3;
    return;
  }
  uVar1 = FUN_005f7c90(*(undefined4 *)(in_ECX + 0x28));
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  return;
}

