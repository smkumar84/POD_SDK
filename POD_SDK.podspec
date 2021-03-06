#
# Be sure to run `pod lib lint POD_SDK.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'POD_SDK'
  s.version          = '1.2.1'
  s.summary          = 'generate tags and improve search results description of POD_SDK.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'Write the description between the DESC delimiters belowthe DESC delimiters belowthe DESC delimiters below'

  s.homepage         = 'https://github.com/smkumar84/POD_SDK'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'smkumar84' => 'smkumar84@gmail.com' }
  s.source           = { :git => 'https://github.com/smkumar84/POD_SDK.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

s.platform     = :ios, "9.3"

  s.source_files = 'POD_SDK/Classes/**/*'
  #s.vendored_frameworks = 'POD_SDK/Frameworks/POD_SDK.framework'
   s.frameworks = 'POD_SDK/Frameworks/MaheshSDK.framework'
  # s.frameworks = 'QuartzCore'

  # s.resource_bundles = {
  #   'POD_SDK' => ['POD_SDK/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
