/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x599830; label: FUN_00599830
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00599830(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  
  cVar1 = *(char *)(param_1 + 0x7b3);
  if (cVar1 == '\0') {
    uVar4 = *(undefined2 *)(param_1 + 0x5a);
    uVar2 = *(undefined2 *)(param_1 + 0x58);
    uVar5 = 0x41400000;
  }
  else {
    if (cVar1 != '\x05') {
      if (((cVar1 == '\x02') || (cVar1 == '\x03')) || (cVar1 == '\x06')) {
        if (0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) {
          uVar5 = FUN_006e6b90(0);
          uVar4 = FUN_00550100(*(undefined2 *)(param_1 + 0x58),param_2,uVar5);
          *(undefined2 *)(param_1 + 0x58) = uVar4;
        }
        uVar4 = FUN_00550070(*(undefined2 *)(param_1 + 0x27a),*(undefined2 *)(param_1 + 0x58),
                             0x41200000);
        *(undefined2 *)(param_1 + 0x27a) = uVar4;
        *(undefined2 *)(param_1 + 0x5a) = *(undefined2 *)(param_1 + 0x58);
      }
      return 1;
    }
    iVar3 = *(int *)(param_1 + 0x790);
    if (iVar3 != 0) {
      uVar4 = FUN_005be2d0(*(float *)(iVar3 + 0x80) - *(float *)(param_1 + 0x80),
                           *(float *)(iVar3 + 0x88) - *(float *)(param_1 + 0x88));
      *(undefined2 *)(param_1 + 0x5a) = uVar4;
    }
    uVar4 = *(undefined2 *)(param_1 + 0x5a);
    uVar2 = *(undefined2 *)(param_1 + 0x58);
    uVar5 = 0x41000000;
  }
  uVar4 = FUN_00550070(uVar2,uVar4,uVar5);
  *(undefined2 *)(param_1 + 0x58) = uVar4;
  *(undefined2 *)(param_1 + 0x27a) = uVar4;
  return 1;
}

