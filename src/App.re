/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 *
 * Converted from https://github.com/facebook/react-native/blob/724fe11472cb874ce89657b2c3e7842feff04205/template/App.js
 * With a few tweaks
 */
open ReactNative;
open Utils;

type reactNativeNewAppScreenColors = {
  .
  "primary": string,
  "white": string,
  "lighter": string,
  "light": string,
  "black": string,
  "dark": string,
};

[@bs.module "react-native/Libraries/NewAppScreen"]
external colors: reactNativeNewAppScreenColors = "Colors";

[@bs.module "react-native/Libraries/Core/Devtools/openURLInBrowser"]
external openURLInBrowser: string => unit = "default";

// [@bs.module ""]
module Header = {
  [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
  let make = (~text) => {

    let background = 

      Style.(
            style(
              ~paddingBottom = 40.->dp,
              ~paddingTop = 96.->dp,
              ~paddingHorizontal = 32.->dp,
              ~backgroundColor = Color.lightgray,
              ()));
    let logo =
      Style.( 
            style(
              ~opacity = 0.33,
              ~overflow = `visible,
              ~resizeMode = `cover,
              ~marginLeft = (-69.)->dp,
              ~marginBottom = (-69.)->dp,
              ()));
    let text_style =
      Style.( 
            style(
              ~fontSize = 14.,
              ~fontWeight = `bold,
              ~textAlign = `center,
              ~color = Color.black,
              ()));
        
    let img_src = Image.Source.fromRequired(Packager.require("./ic_launcher.png"));

    <ImageBackground
      source=img_src
      style=background
      imageStyle=logo >
      <Text style=text_style>text->React.string</Text>
    </ImageBackground>
  };
};

module ReloadInstructions = {
  [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
  external make: _ => React.element = "ReloadInstructions";
  
};
module DebugInstructions = {
  [@react.component] [@bs.module "react-native/Libraries/NewAppScreen"]
  external make: _ => React.element = "DebugInstructions";
};

/*
 Here is StyleSheet that is using Style module to define styles for your components
 The main different with JavaScript components you may encounter in React Native
 is the fact that they **must** be defined before being referenced
 (so before actual component definitions)
 More at https://reasonml-community.github.io/reason-react-native/en/docs/apis/Style/
 */
let styles =
  Style.(
    StyleSheet.create({
      "scrollView": style(~backgroundColor=colors##lighter, ()),
      "engine": style(~position=`absolute, ~right=0.->dp, ()),
      "body": style(~backgroundColor=colors##white, ()),
      "sectionContainer":
        style(~marginTop=32.->dp, ~paddingHorizontal=24.->dp, ()),
      "sectionTitle":
        style(~fontSize=24., ~fontWeight=`_600, ~color=colors##black, ()),
      "sectionDescription":
        style(
          ~marginTop=2.->dp,
          ~fontSize=12.,
          ~fontWeight=`_400,
          ~color=colors##dark,
          (),
        ),
      "highlight": style(~fontWeight=`_700, ~color="#00FF00FF", ()),
      "footer":
        style(
          ~color=colors##dark,
          ~fontSize=12.,
          ~fontWeight=`_600,
          ~padding=4.->dp,
          ~paddingRight=12.->dp,
          ~textAlign=`right,
          (),
        ),
      "text": 
        style(
          ~color=colors##dark,
          ~fontSize=19.,
          ~fontWeight=`_300,
          ~padding=4.->dp,
          ~paddingRight=12.->dp,
          ~textAlign=`right,
        )
    })
  );

[@react.component]


module Highlight = { 
  [@react.component]
  let make = (~txt) => {
    <Text style={styles##highlight}>
      txt->React.string
    </Text>
  };
};

module MainScreen = {
  [@react.component]
  let make = () => {
    <ScrollView
      contentInsetAdjustmentBehavior=`automatic style={styles##scrollView}>
      <Header text="SoundScapeTK-rn"/>

      <View style={styles##body}>
        <View style={styles##sectionContainer}>
          <Text style={styles##sectionTitle}>
            "Regions..."->React.string
          </Text>
        </View>
      
        <View style={styles##sectionContainer}>
          <Text style={styles##sectionTitle}>
            "Map..."->React.string
          </Text>
        </View>
      
        <View style={styles##sectionContainer}>
          <Text style={styles##sectionTitle}>
            "About..."->React.string
          </Text>
          <TouchableOpacity
            onPress={_ =>
              openURLInBrowser(
                "https://github.com/kitefishlabs/SoundScapeTKrn",
              )
            }>
            <Text
              style=Style.(
                style(
                  ~marginTop=8.->dp,
                  ~fontSize=18.,
                  ~fontWeight=`_400,
                  ~color=colors##primary,
                  (),
                )
              )>
              "Github"
              ->React.string
            </Text>
          </TouchableOpacity>
          <TouchableOpacity
            onPress={_ =>
              openURLInBrowser(
                "https://kitefishlabs.com/reason-react-native",
              )
            }>
            <Text
              style=Style.(
                style(
                  ~marginTop=8.->dp,
                  ~fontSize=18.,
                  ~fontWeight=`_400,
                  ~color=colors##primary,
                  (),
                )
              )>
              "Kitefish Labs"
              ->React.string
            </Text>
          </TouchableOpacity>
        </View>
      </View>
    </ScrollView>
  };
};

let app = () =>
  <>
    <StatusBar barStyle=`darkContent />
    <SafeAreaView>
      <MainScreen />
    </SafeAreaView>
  </>;
