/* Ghidra pseudocode, not original source.
 * ev_cdce1c1a74417fce840dfa63a2c32577050f1657d9e1cb9f16f7031f05578a24
 * Entry: 0x42b960; label: FUN_0042b960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b960(void)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  float10 fVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  char acStack_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)acStack_24;
  if (((_DAT_0093b2ac & 0x20) != 0) && (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200) != -1))
  {
    FUN_0048a1c0((int)*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200),PTR_DAT_00802c54);
  }
  FUN_0056e560();
  if (*(int *)(PTR_DAT_00802c54 + 0x130) != 0) {
    FUN_0048c3f0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),*(undefined4 *)(PTR_DAT_00802c54 + 0x130)
                );
    *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) =
         *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) | 1;
  }
  FUN_0056a7c0(PTR_DAT_00802c54);
  DAT_0093b0e4 = 0;
  FUN_00552ac0();
  FUN_00552ac0();
  FUN_0057edc0(PTR_DAT_00802c54);
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  if ((_DAT_0093b2ac & 0x40) == 0) {
    FUN_0042b7c0();
  }
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  FUN_00424500(DAT_00856980);
  FUN_00572380();
  FUN_005a40d0();
  FUN_0057f970();
  FUN_00404990();
  FUN_00426b30();
  FUN_0064a480();
  FUN_0056e5d0();
  FUN_0058b3a0();
  FUN_004ba190();
  FUN_0054a2f0(PTR_DAT_008021b4);
  FUN_00560b40();
  FUN_0059fe10();
  FUN_005765f0();
  FUN_005765b0();
  FUN_004ce590(PTR_DAT_00802c54);
  FUN_004d4810(*(undefined4 *)(PTR_DAT_00802c54 + 0x5168));
  FUN_005a2fd0(*(undefined4 *)(PTR_DAT_00802c54 + 0x5050));
  FUN_00698910();
  FUN_00548fb0(&DAT_0092505c,0);
  FUN_00548fb0(&DAT_00924fdc,0);
  FUN_00548fb0(&DAT_00924ff8,0);
  FUN_00548fb0(&DAT_00925044,0);
  if (((_DAT_0093b2ac & 0x20) != 0) && (DAT_009553d4 != 0)) {
    FUN_00548fb0(DAT_009553d4 + 8,0);
  }
  FUN_00576910(0xffffffff,0,0);
  FUN_00548780();
  _DAT_00855f74 = 0;
  _DAT_00876cdc = 0;
  _DAT_00876ce4 = 0;
  DAT_00876cd8 = 0;
  FUN_005a22b0(DAT_00876688);
  FUN_004710d0(PTR_DAT_00802c54);
  FUN_005a1d80(PTR_DAT_00802c54);
  _DAT_00924ddc = 0x40400000;
  _DAT_00876830 = 0x3f800000;
  DAT_008020c0 = 0xffffffff;
  _DAT_00876834 = 0x3f800000;
  _DAT_007f5dc8 = 0xffffffff;
  _DAT_00925058 = 0;
  _DAT_007f5dc4 = 0xffffffff;
  _DAT_009250ac = 0;
  if (DAT_00951ba4 != 0) {
    _DAT_00925058 = 0x40400000;
  }
  _memset(&DAT_009559d8,0,0x144);
  if (DAT_00951288 == 0) {
    DAT_0087a834 = 0x2000;
    _DAT_0087a930 = 0x3e800000;
    DAT_0087a838 = 0x1555;
    _DAT_0087aa54 = 0x3f800000;
LAB_0042bc6a:
    DAT_0087a958 = 0x2aaa;
  }
  else {
    if ((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b210) &&
       (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b24c)) {
      DAT_0087a834 = 0x1c71;
      _DAT_0087a930 = 0x40c80000;
      DAT_0087a838 = 0xe38;
      _DAT_0087aa54 = 0x42c80000;
      goto LAB_0042bc6a;
    }
    DAT_0087a958 = 0x38e3;
    _DAT_0087a930 = 0x40c80000;
    DAT_0087a834 = 0x31c7;
    _DAT_0087aa54 = 0x42c80000;
    DAT_0087a838 = 0x2aaa;
  }
  DAT_00876cc8 = 0;
  _DAT_00876840 = 0;
  if (DAT_008765c4 != 0) {
    DAT_0085ea74 = 0;
    DAT_0087a9d0 = 0;
    DAT_0087a9cc = 0;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x298c) != 0) {
    *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0x210) =
         *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0x210) & 0xfffffffe;
  }
  if ((_DAT_0093b2ac & 0x20) != 0) {
    FUN_00559af0(PTR_DAT_00802c54,(int)*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200));
  }
  FUN_005a1a70(*(undefined4 *)(PTR_DAT_00802c54 + 0x2960),
               (int)*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200));
  FUN_00559be0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),PTR_DAT_00802c54,
               (int)*(char *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200));
  if ((_DAT_0093b2ac & 1) == 0) {
    FUN_0059fbe0(0);
  }
  else {
    FUN_004ba2d0();
    FUN_004a48f0();
    FUN_00414f20();
    FUN_0043fda0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8));
    FUN_0059fbe0(1);
    FUN_005143a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8));
    piVar3 = &DAT_0093d7f0;
    do {
      if (*piVar3 != 0) {
        FUN_0041b0a0(*piVar3);
        if (DAT_0093b2a4 == 0) {
          iVar2 = FUN_0058a900(0);
          if (iVar2 != 0) {
            iVar2 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"Mission",0,1,0);
            if (iVar2 == 0) {
LAB_0042becc:
              iVar2 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"party",0,1,0);
              if (iVar2 == 0) {
                pcVar7 = "GeneralParty";
              }
              else {
                pcVar7 = "party";
              }
            }
            else {
              pcVar7 = "Mission";
            }
            goto LAB_0042bf03;
          }
          iVar2 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),
                               *(undefined4 *)(*(int *)(*piVar3 + 0x54) + 0xc),0,1,0);
          if (iVar2 != 0) {
            pcVar7 = *(char **)(*(int *)(*piVar3 + 0x54) + 0xc);
            goto LAB_0042bf03;
          }
          uVar1 = *(uint *)(*(int *)(*piVar3 + 0x54) + 4);
          if ((uVar1 & 8) == 0) {
            if ((uVar1 & 0x80) == 0) {
              pcVar7 = "NoWeapon";
            }
            else {
              pcVar7 = "Blaster";
            }
          }
          else {
            pcVar7 = "Jedi";
          }
          _sprintf(acStack_24,pcVar7);
          iVar2 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),acStack_24,0,1,0);
          if (iVar2 == 0) goto LAB_0042becc;
        }
        else {
          iVar2 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"Freeplay",0,1);
          if (iVar2 == 0) {
            iVar2 = FUN_00513010(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),"party",0,1,0);
            if (iVar2 == 0) {
              pcVar7 = "GeneralParty";
            }
            else {
              pcVar7 = "party";
            }
          }
          else {
            pcVar7 = "Freeplay";
          }
LAB_0042bf03:
          _sprintf(acStack_24,pcVar7);
        }
        FUN_00514640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),*piVar3 + 0x2c8,*piVar3 + 0x2c8,0,
                     acStack_24,0,1,0,0);
        if ((((DAT_0093b2a4 == 0) && (iVar2 = FUN_0058a900(0), iVar2 == 0)) &&
            (*(int *)(*piVar3 + 0xcd0) == 0)) &&
           (iVar2 = FUN_0052c790(*piVar3 + 0x2c8,"InActive"), iVar2 != 0)) {
          *(uint *)(*piVar3 + 0x1fc) = *(uint *)(*piVar3 + 0x1fc) & 0xffffefff;
        }
      }
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x93d810);
  }
  if (DAT_008765c0 != 0) {
    FUN_0043a910(0);
  }
  if ((_DAT_0093b2ac & 2) != 0) {
    if (DAT_0093d7f0 != 0) {
      *(undefined1 *)(DAT_0093d7f0 + 0xe39) = 4;
    }
    if (DAT_0093d7f4 != 0) {
      *(undefined1 *)(DAT_0093d7f4 + 0xe39) = 4;
    }
    if (DAT_0093d7f8 != 0) {
      *(undefined1 *)(DAT_0093d7f8 + 0xe39) = 4;
    }
    if (DAT_0093d7fc != 0) {
      *(undefined1 *)(DAT_0093d7fc + 0xe39) = 4;
    }
    if (DAT_0093d800 != 0) {
      *(undefined1 *)(DAT_0093d800 + 0xe39) = 4;
    }
    if (DAT_0093d804 != 0) {
      *(undefined1 *)(DAT_0093d804 + 0xe39) = 4;
    }
    if (DAT_0093d808 != 0) {
      *(undefined1 *)(DAT_0093d808 + 0xe39) = 4;
    }
    if (DAT_0093d80c != 0) {
      *(undefined1 *)(DAT_0093d80c + 0xe39) = 4;
    }
  }
  if ((_DAT_0093b2ac & 4) != 0) {
    if (DAT_0093d7f0 != 0) {
      if ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d7f0 + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d7f0 + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d7f4 != 0) {
      if ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d7f4 + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d7f4 + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d7f8 != 0) {
      if ((*(byte *)(DAT_0093d7f8 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d7f8 + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d7f8 + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d7fc != 0) {
      if ((*(byte *)(DAT_0093d7fc + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d7fc + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d7fc + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d800 != 0) {
      if ((*(byte *)(DAT_0093d800 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d800 + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d800 + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d804 != 0) {
      if ((*(byte *)(DAT_0093d804 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d804 + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d804 + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d808 != 0) {
      if ((*(byte *)(DAT_0093d808 + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d808 + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d808 + 0x1000) = 0x40200000;
      }
    }
    if (DAT_0093d80c != 0) {
      if ((*(byte *)(DAT_0093d80c + 0x1fc) & 0x80) == 0) {
        *(undefined4 *)(DAT_0093d80c + 0x1000) = 0;
      }
      else {
        *(undefined4 *)(DAT_0093d80c + 0x1000) = 0x40200000;
      }
    }
  }
  FUN_004bcaf0();
  FUN_00570fb0(PTR_DAT_00802c54);
  FUN_00573690(PTR_DAT_00802c54);
  FUN_004018a0(*(undefined4 *)(PTR_DAT_00802c54 + 0x4678));
  FUN_004027a0(PTR_DAT_00802c54,*(undefined4 *)(PTR_DAT_00802c54 + 0x4678));
  if ((_DAT_0093b2ac & 0x10) != 0) {
    piVar3 = &DAT_0093d7f0;
    do {
      if (*piVar3 != 0) {
        FUN_0041b420(*piVar3,1,0,0);
      }
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x93d810);
    fVar5 = (float10)FUN_00499920();
    _DAT_0087b8b8 = (float)fVar5;
  }
  _DAT_0087a9a0 = 0;
  _DAT_0087a9a4 = 0;
  puVar4 = &DAT_0087aad8;
  do {
    iVar2 = FUN_005cfac0(puVar4);
    if (iVar2 != 0) {
      uVar6 = __allshl();
      _DAT_0087a9a0 = _DAT_0087a9a0 | (uint)uVar6;
      _DAT_0087a9a4 = _DAT_0087a9a4 | (uint)((ulonglong)uVar6 >> 0x20);
    }
    puVar4 = puVar4 + 3;
  } while ((int)puVar4 < 0x87aef8);
  *(undefined4 *)(PTR_DAT_00802c54 + 0x50cc) = 0;
  if (*(code **)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0x70) != (code *)0x0) {
    (**(code **)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0x70))(PTR_DAT_00802c54);
  }
  FUN_0058ba40(*(undefined4 *)(PTR_DAT_00802c54 + 0x2adc));
  FUN_00548930(PTR_DAT_00802c54,&DAT_008668cc);
  DAT_00876571 = DAT_008668d1;
  DAT_0087656c._3_1_ = DAT_008668cf;
  DAT_00876570 = DAT_008668d0;
  if ((((*(int *)(PTR_DAT_00802c54 + 0x130) != 0) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) & 2) == 0)) &&
      ((*(int *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 4) != 0 &&
       ((DAT_00951428 == 0 && (DAT_00951388 == 0)))))) && (DAT_008765cc == 0)) {
    FUN_00577790(*(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x2ac4) + 4),0,0x40000000,0,0x3f800000,
                 0,1);
  }
  DAT_00951428 = 0;
  DAT_008765cc = 0;
  if (DAT_00951c74 != 0) {
    FUN_0057cd30(DAT_00951c74,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),0,0);
    DAT_00951c74 = 0;
  }
  if (DAT_00951154 != 0) {
    FUN_0056e2e0(1);
  }
  DAT_008668c4 = FUN_0046c350(PTR_DAT_00802c54,0,0,0,0,0,0,0);
  if (1000000 < DAT_008668c4) {
    DAT_008668c4 = 1000000;
  }
  if (DAT_00951b50 != 0) {
    DAT_008668c4 = 1000000;
  }
  _DAT_0093b2ac = 0;
  DAT_008765c4 = 0;
  _DAT_008765c8 = 0;
  FUN_0057ceb0();
  if (DAT_02962034 == 0) {
    FUN_00698e70();
  }
  *(undefined4 *)(PTR_DAT_00802c54 + 0x118) = 1;
  DAT_00925398 = 0;
  FUN_0043d500(1);
  if (*(int *)(PTR_DAT_00802c54 + 0x130) == 0) {
LAB_0042c42a:
    uVar8 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2acc);
    iVar2 = 0;
  }
  else {
    if ((*(uint *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) & 2) != 0) {
      *(uint *)(PTR_DAT_00802c54 + 0x5170) =
           *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x130) + 0x2800) >> 2 & 1;
    }
    if (*(int *)(PTR_DAT_00802c54 + 0x130) == 0) goto LAB_0042c42a;
    uVar8 = *(undefined4 *)(PTR_DAT_00802c54 + 0x2acc);
    iVar2 = *(int *)(PTR_DAT_00802c54 + 0x130) + 0x2c24;
  }
  FUN_0059f4e0(uVar8,iVar2);
  FUN_0048a170(*(undefined4 *)(PTR_DAT_00802c54 + 0x130));
  if (DAT_007f39e4 != 0) {
    if ((DAT_00951364 != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_00951364)) {
      uVar8 = 3;
      goto LAB_0042c47e;
    }
    if (DAT_00876580 == 0) {
      uVar8 = 1;
      goto LAB_0042c47e;
    }
  }
  uVar8 = 2;
LAB_0042c47e:
  FUN_00486f50(uVar8);
  if ((*(int *)(PTR_DAT_00802c54 + 300) == 0) ||
     (DAT_00955594 = 1, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af74)) {
    DAT_00955594 = 0;
  }
  DAT_0087950c = 0;
  if ((((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x10) != 0)) &&
      (DAT_00951238 < DAT_00951230)) && (DAT_00951238 = DAT_00951230, 10 < DAT_00951230)) {
    DAT_00951238 = 10;
  }
  __security_check_cookie(local_4 ^ (uint)acStack_24);
  return;
}

